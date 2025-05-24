"""
This is the code for Fortran to C++ code translation. Using GPT-4 as the teacher model.

"""
# import sys
# sys.path.append('..')
import os
import glob
import re
import json
import pandas as pd
import subprocess
import tiktoken
from datasets import load_dataset

from utils.prompt import * 
from utils.model_utils import *

DEFAULT_MODEL_ID="gpt-4o-mini"
TIMEOUT_LIMIT=60 # timeout limit in seconds for compiling or running original or translation generated code

import logging

# Set up logging to capture errors
file_handler = logging.FileHandler('data_generation.log') #, buffering=128)  # 128 bytes buffer
logging.basicConfig(
    handlers=[file_handler],
    level=logging.DEBUG,
    format='%(asctime)s - %(levelname)s - %(message)s'
    )

# Function to get the OpenAI API key from environment variables
def get_openai_api_key():
    api_key = os.getenv('OPENAI_API_KEY')
    if not api_key:
        raise ValueError("OpenAI API key not found. Please set the OPENAI_API_KEY environment variable.")
    # assign to a global variable!!
    return api_key

#this function is not used right now.
# def remove_fortran_comments_fixed(code):
#     """
#     ### Code from Naveed Ahmed Sekender ###
#     Removes comments uniformly from Fortran code (marked by '!', 'C', 'c', or '*'), 
#     while preserving lines containing OpenMP directives.
#     """
#     # Patterns to identify comments and directives
#     omp_directives_pattern = re.compile(r'^[ \t]*[!C\*]\$OMP', re.IGNORECASE)
#     old_style_comment_pattern = re.compile(r'^[ \t]*[Cc\*]')
#     comment_pattern = re.compile(r'!(?![$]omp).*$', re.IGNORECASE)

#     lines = code.split('\n')
#     cleaned_lines = []

#     for line in lines:
#         if omp_directives_pattern.search(line):
#             # Remove non-directive comments from lines containing OpenMP directives
#             line = comment_pattern.sub('', line)
#             cleaned_lines.append(line.strip())
#             continue

#         # Check and skip old-style comments if they are not OpenMP directives
#         if old_style_comment_pattern.match(line) and not omp_directives_pattern.match(line):
#             continue

#         # Remove standard comments
#         line = comment_pattern.sub('', line)

#         if line.strip():
#             cleaned_lines.append(line.strip())

#     return '\n'.join(cleaned_lines)


def generate_str_answer_gpt(input_prompt_gpt, max_tokens, gpt_model = DEFAULT_MODEL_ID):
    """
    Generates a response from GPT-4 based on the provided prompt.

    Parameters:
    - input_prompt_gpt (str): The prompt to be sent to GPT-4.
    - max_tokens (int): The maximum number of tokens to generate.
    - gpt_model (str): The GPT model to use (default is "gpt-4o-mini").

    Returns:
    - str: The content of the response from GPT-4.
    """
    messages = []
    message = {
        "role": "user",
        "content": input_prompt_gpt
    }
    messages.append(message)
    answer = generate_from_GPT(key,prompts=messages, 
                                    max_tokens=max_tokens, 
                                    model=gpt_model, 
                                    n=1)[0]["message"]["content"]
    return answer


def fur_modification(history, ser_messages, modification_prompt, max_tokens = 4096):
    """
    Modifies the code based on the provided prompt and updates the history and messages.

    Parameters:
    - history (list): The conversation history to be updated.
    - ser_messages (list): The list of messages exchanged during the conversation.
    - modification_prompt (str): The prompt used to generate modifications.
    - max_tokens (int): The maximum number of tokens to generate.

    Updates:
    - history: Appends the modification prompts and responses to the history.
    - ser_messages: Appends the modified prompts and responses.
    """
    m_ser = {
        "role": "user",
        "content": modification_prompt
    }
    history.append(m_ser)
    ser_messages.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model=DEFAULT_MODEL_ID, 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]    
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his)

def add_to_json(history, file_path='dialogues.json'):
    """
    Adds the conversation history to a JSON file.

    Parameters:
    - history (list): The conversation history to be added.
    - file_path (str): The path to the JSON file where the history will be stored.
    """
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            try:
                dialogues = json.load(file)
            except json.JSONDecodeError:
                dialogues = []
    else:
        dialogues = []

    new_id = 1 if not dialogues else dialogues[-1]["id"] + 1

    new_dialogue = {
        "id": new_id,
        "messages": history
    }
    dialogues.append(new_dialogue)
    
    with open(file_path, 'w') as file:
        json.dump(dialogues, file, indent=4)
     

def run_codes(cuda_folder, cuda_code_exe, cpp_folder, c_code_exe, timeout_seconds=TIMEOUT_LIMIT):
    """
    Compiles and runs CUDA and C++ code and captures their output.

    Parameters:
    - cuda_folder (str): Directory where CUDA code and binaries are stored.
    - cuda_code_exe (str): The CUDA code (e.g., a kernel) to be compiled and executed.
    - cpp_folder (str): Directory where C++ code and binaries are stored.
    - c_code_exe (str): The translated C++ code to be compiled and executed.
    - timeout_seconds (int): Timeout limit for the compilation and execution.

    Returns:
    - tuple: Contains stdout, stderr, and pass/fail status for both CUDA and C++ programs.
    """

    # Write CUDA code to file
    cuda_file_path = os.path.join(cuda_folder, 'test.cu')
    with open(cuda_file_path, 'w') as file:
        file.write(cuda_code_exe)

    # Write C++ code to file
    cpp_file_path = os.path.join(cpp_folder, 'test.cpp')
    with open(cpp_file_path, 'w') as file:
        file.write(c_code_exe)

    # Compile CUDA code using nvcc
    cuda_compile_cmd = f'nvcc {cuda_file_path} -o {cuda_folder}/test_cuda'
    cuda_compile_process = subprocess.run(cuda_compile_cmd, 
                                          shell=True, 
                                          capture_output=True,
                                          timeout=timeout_seconds)
    cuda_stderr = cuda_compile_process.stderr
    cuda_stdout = cuda_compile_process.stdout
    if cuda_compile_process.returncode != 0:
        cuda_p_f = False
        cuda_stdout = cuda_stdout.decode('utf-8', 'replace')
        cuda_stderr = cuda_stderr.decode('utf-8', 'replace')
    else:
        cuda_p_f = True  
        cuda_run_cmd = f'{cuda_folder}/test_cuda'
        try:
            cuda_run_process = subprocess.run(cuda_run_cmd, 
                                              shell=True, 
                                              capture_output=True,
                                              timeout=timeout_seconds)
            cuda_stdout = cuda_run_process.stdout.decode('utf-8', 'replace')
            cuda_stderr = cuda_run_process.stderr.decode('utf-8', 'replace')
        except subprocess.TimeoutExpired:
            cuda_p_f = False
            cuda_stdout = ''
            cuda_stderr = 'It seems that the program hangs. CUDA execution timed out.'

    # Compile C++ code
    cpp_compile_cmd = f'g++ -fopenmp {cpp_file_path} -o {cpp_folder}/test_cpp'
    cpp_compile_process = subprocess.run(cpp_compile_cmd, 
                                         shell=True, 
                                         capture_output=True,
                                         timeout=timeout_seconds)
    cpp_stderr = cpp_compile_process.stderr
    cpp_stdout = cpp_compile_process.stdout
    if cpp_compile_process.returncode != 0:
        cpp_p_f = False
        cpp_stdout = cpp_stdout.decode('utf-8', 'replace')
        cpp_stderr = cpp_stderr.decode('utf-8', 'replace')
    else:
        cpp_p_f = True  
        cpp_run_cmd = f'{cpp_folder}/test_cpp'
        try:
            cpp_run_process = subprocess.run(cpp_run_cmd, 
                                             shell=True, 
                                             capture_output=True,
                                             timeout=timeout_seconds)
            cpp_stdout = cpp_run_process.stdout.decode('utf-8', 'replace')
            cpp_stderr = cpp_run_process.stderr.decode('utf-8', 'replace')
        except subprocess.TimeoutExpired:
            cpp_p_f = False
            cpp_stdout = ''
            cpp_stderr = 'It seems that the program hangs! C++ execution timed out.'

    return cuda_stdout, cuda_stderr, cuda_p_f, cpp_stdout, cpp_stderr, cpp_p_f

# def run_codes(fortran_folder, f_code_exe, cpp_folder, c_code_exe, timeout_seconds=TIMEOUT_LIMIT):
#     """
#     Compiles and runs Fortran and C++ code and captures their output.

#     Parameters:
#     - fortran_folder (str): The directory where Fortran code and binaries are stored.
#     - f_code_exe (str): The Fortran code to be compiled and executed.
#     - cpp_folder (str): The directory where C++ code and binaries are stored.
#     - c_code_exe (str): The C++ code to be compiled and executed.
#     - timeout_seconds (int): The timeout for the compilation and execution processes.

#     Returns:
#     - tuple: Contains stdout and stderr of the Fortran and C++ programs, and their success status.
#     """

#     fortran_file_path = os.path.join(fortran_folder, 'test.f90')
#     with open(fortran_file_path, 'w') as file:
#         file.write(f_code_exe)

#     cpp_file_path = os.path.join(cpp_folder, 'test.cpp')
#     with open(cpp_file_path, 'w') as file:
#         file.write(c_code_exe)

#     # The -J {fortran_folder} option in the gfortran command is used to 
#     # specify the directory where the generated object files should be placed.
#     fortran_compile_cmd = f'gfortran -fopenmp -J {fortran_folder} -o {fortran_folder}/test {fortran_file_path}'
#     fortran_compile_process = subprocess.run(fortran_compile_cmd, 
#                                                 shell=True, 
#                                                 capture_output=True,
#                                                 timeout=timeout_seconds)
#     fortran_stderr = fortran_compile_process.stderr
#     fortran_stdout = fortran_compile_process.stdout
#     if fortran_compile_process.returncode != 0:
#         fortran_p_f = False
#     else:
#         fortran_p_f = True  
#         fortran_run_cmd = f'{fortran_folder}/test'
#         try:
#             fortran_run_process = subprocess.run(fortran_run_cmd, 
#                                                     shell=True, 
#                                                     capture_output=True,
#                                                     timeout=timeout_seconds)
#             fortran_stdout = fortran_run_process.stdout.decode('utf-8', 'replace')
#             fortran_stderr = fortran_run_process.stderr.decode('utf-8', 'replace')
#         except subprocess.TimeoutExpired: # avoid infinite loop
#             fortran_p_f = False
#             fortran_stdout = ''
#             fortran_stderr = b'It seems that the program hangs. Fortran execution timed out.'
#         # delete generated .mod files
#         mod_files = glob.glob(f'{fortran_folder}/*.mod')
#         for file in mod_files:
#             os.remove(file)
#     # This is no longer true: C++ code may have unit testing using Google Tests
# #cpp_compile_cmd = f'g++ -fopenmp {cpp_file_path} -lgtest -lgtest_main -pthread -o {cpp_folder}/test'
#     cpp_compile_cmd = f'g++ -fopenmp {cpp_file_path} -o {cpp_folder}/test'
#     cpp_compile_process = subprocess.run(cpp_compile_cmd, 
#                                             shell=True, 
#                                             capture_output=True,
#                                             timeout=timeout_seconds)
#     cpp_stderr = cpp_compile_process.stderr
#     cpp_stdout = cpp_compile_process.stdout
#     if cpp_compile_process.returncode != 0:
#         cpp_p_f = False
#     else:
#         cpp_p_f = True  
#         cpp_run_cmd = f'{cpp_folder}/test'
#         try:
#             cpp_run_process = subprocess.run(cpp_run_cmd, 
#                                                 shell=True, 
#                                                 capture_output=True,
#                                                 timeout=timeout_seconds)    
#             cpp_stdout = cpp_run_process.stdout.decode('utf-8', 'replace')
#             cpp_stderr = cpp_run_process.stderr.decode('utf-8', 'replace')
#         except subprocess.TimeoutExpired: # avoid infinite loop
#             cpp_p_f = False
#             cpp_stdout = ''
#             cpp_stderr = b'It seems that the program hangs! C++ execution timed out.'
#     return fortran_stdout, fortran_stderr, fortran_p_f, cpp_stdout, cpp_stderr, cpp_p_f


def extract_codes(cuda_code_exe, cpp_code_exe, str_exe):
    """
    Extracts CUDA and C++ code blocks from the generated response string (str_exe).

    Parameters:
    - cuda_code_exe (str): Placeholder to store original CUDA source code.
    - cpp_code_exe (str): Placeholder to store translated C++ source code.
    - str_exe (str): String containing both CUDA and C++ code, likely from GPT output.

    Returns:
    - tuple: (cuda_code_exe, cpp_code_exe)
    """

    cuda_code_exe = ""
    cpp_code_exe = ""

    current_section = None
    lines = str_exe.split('\n')

    for line in lines:
        # Section markers in GPT output (may vary depending on prompt formatting)
        if "```cuda" in line or "```cu" in line:
            current_section = "cuda"
            continue
        elif "```cpp" in line or "```c++" in line or "```c" in line:
            current_section = "cpp"
            continue
        elif "```" in line:
            current_section = None
            continue

        if current_section == "cuda":
            cuda_code_exe += line + '\n'
        elif current_section == "cpp":
            cpp_code_exe += line + '\n'

    return cuda_code_exe.strip(), cpp_code_exe.strip()


# def extract_codes(f_code_exe, c_code_exe, Str_Exe):
#     """
#     Extracts Fortran and C++ code snippets from the provided text.
#     Use them to update the current codes, if any.

#     Parameters:
#     - f_code_exe (str): The current Fortran code.
#     - c_code_exe (str): The current C++ code.
#     - Str_Exe (str): The text containing the code snippets.

#     Returns:
#     - tuple: Updated Fortran and C++ code snippets.
#     """

#     fortran_start = Str_Exe.find("```fortran") + 10
#     if fortran_start != 9:
#         fortran_end = Str_Exe.find("```", fortran_start)
#         f_code_exe = Str_Exe[fortran_start:fortran_end].strip()
        
#     cpp_start = Str_Exe.find("```cpp") + 6
#     if cpp_start != 5:
#         cpp_end = Str_Exe.find("```", cpp_start)
#         c_code_exe = Str_Exe[cpp_start:cpp_end].strip()   

#     # try:
#     #     f_code_exe
#     # except NameError:
#     #     f_code_exe = ""

#     # try:
#     #     c_code_exe
#     # except NameError:
#     #     c_code_exe = ""
    
#     return f_code_exe, c_code_exe

def update_code_from_history(cuda_code_exe, cpp_code_exe, history):
    """
    Update CUDA and C++ code from the history of previous interactions.

    Args:
        cuda_code_exe (str): The current CUDA code to be updated.
        cpp_code_exe (str): The current C++ code to be updated.
        history (list): A list of historical messages containing code updates.

    Returns:
        tuple: Updated CUDA and C++ code.
    """
    # Get the latest model output
    str_exe = history[-1]["content"]

    # Decode any unicode escape characters (e.g., \n, \t)
    str_exe = str_exe.encode().decode('unicode_escape')

    # Extract CUDA and C++ code blocks from the string
    cuda_code_exe, cpp_code_exe = extract_codes(cuda_code_exe, cpp_code_exe, str_exe)

    return cuda_code_exe, cpp_code_exe

# def update_code_from_history(f_code_exe, c_code_exe, history):
#     """
#     Update Fortran and C++ code from the history of previous interactions.

#     Args:
#         f_code_exe (str): The current Fortran code to be updated.
#         c_code_exe (str): The current C++ code to be updated.
#         history (list): A list of historical messages containing code updates.

#     Returns:
#         tuple: Updated Fortran and C++ code.
#     """
#     Str_Exe = history[-1]["content"]
#     Str_Exe = Str_Exe.encode().decode('unicode_escape')
#     f_code_exe, c_code_exe = extract_codes(f_code_exe, c_code_exe, Str_Exe)
#     return f_code_exe, c_code_exe
    

def Ai_chat_with_Ai(key, cuda_code, max_tokens, gpt_model=DEFAULT_MODEL_ID, turns_limitation=3, idx=0):
    """
    Simulate a conversation between a questioner and a solver using an AI model to translate CUDA code
    to C++ and generate unit tests, handling errors and updates iteratively.

    Args:
        key (str): API key for accessing the AI model.
        cuda_code (str): The CUDA code to be translated and tested.
        max_tokens (int): Maximum number of tokens for AI responses.
        gpt_model (str): Model name for the AI.
        turns_limitation (int): Number of modification turns to perform (default is 3).

    Returns:
        tuple: History of the conversation and a flag indicating if the process should stop.
    """

    qer_messages = []
    ser_messages = []
    history = []

    # define the role of questioner
    m_qer = {
        "role": "system",
        "content": Instruction_qer  # must be CUDA-aware prompt
    }
    qer_messages.append(m_qer)

    # Start the conversation with the user providing CUDA code
    m_qer = {
        "role": "user",
        "content": q_ask_s_translation.format(cuda_code=cuda_code)  # CUDA-based prompt
    }
    qer_messages.append(m_qer)

    # Get response from GPT for C++ translation
    m_qer_gpt = generate_from_GPT(
        key,
        prompts=qer_messages,
        max_tokens=max_tokens,
        model=gpt_model,
        n=1
    )[0]["message"]

    qer_answer = m_qer_gpt["content"]
    qer_messages.append(m_qer_gpt)
    logging.info(f"qer (questioner) asked for the C++ translation:\n{qer_answer}")
    
    # Solver generates the C++ translation
    m_ser = {
        "role": "user",
        "content": f"{qer_answer}"
    }
    ser_messages.append(m_ser)
    history.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]
    logging.info(f"Solver generated the C++ translation:\n{ser_answer}")
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his) 

    # Questioner asks for the unit test
    #-----------------------------------
    m_qer = {
        "role": "user",
        "content": q_ask_s_unit_test.format(ser_answer = ser_answer)
    }  
    qer_messages.append(m_qer)  
    m_qer_gpt = generate_from_GPT(key,prompts=qer_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    qer_answer = m_qer_gpt["content"] 
    logging.info(f"Questioner asks for the unit test:\n{qer_answer}")   
    qer_messages.append(m_qer_gpt)

    # Solver generates the unit test
    m_ser = {
        "role": "user",
        "content": f"{qer_answer}"
    }
    ser_messages.append(m_ser)
    history.append(m_ser)
    m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
                                max_tokens=max_tokens, 
                                model=gpt_model, 
                                n=1)[0]["message"]
    ser_answer = m_ser_gpt["content"]    
    logging.info(f"Solver generate the unit test:\n{ser_answer}")   
    ser_messages_init = ser_messages
    ser_messages.append(m_ser_gpt)
    m_his = {
        "role": "assistant",
        "content": f"{ser_answer}"
    }
    history.append(m_his)  

    """
    Compile, execute, and repair the pair of unit test codes
    """

    cuda_code_exe = ''
    cpp_code_exe = ''
    cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

    for turn in range(turns_limitation):
        logging.info(f"Running modification {turn}th turn")
        
        Init_solver = Init_solver_prompt.format(cuda_code=cuda_code_exe, cpp_code=cpp_code_exe)
        ser_message_unit_test = {
            "role": "assistant",
            "content": f"{Init_solver}"
        }
        ser_messages_init_copy = ser_messages_init.copy()
        ser_messages_init_copy.append(ser_message_unit_test)
        ser_messages = ser_messages_init_copy

        # Create sandbox folders
        cuda_folder = '../sandbox/cuda'
        cpp_folder = '../sandbox/cpp'
        os.makedirs(cuda_folder, exist_ok=True)
        os.makedirs(cpp_folder, exist_ok=True)

        logging.info(f"CUDA code to be executed:\n{cuda_code_exe}")
        logging.info(f"C++ code to be executed:\n{cpp_code_exe}")
        
        cuda_stdout, cuda_stderr, cuda_p_f, cpp_stdout, cpp_stderr, cpp_p_f = run_codes(
            cuda_folder, cuda_code_exe, cpp_folder, cpp_code_exe
        )

        cuda_compile_result = f"CUDA Stdout: {cuda_stdout}\nCUDA Stderr: {cuda_stderr}"
        cpp_compile_result = f"C++ Stdout: {cpp_stdout}\nC++ Stderr: {cpp_stderr}"
        logging.info(f"CUDA compile result in {turn}th turn:\n{cuda_compile_result}")
        logging.info(f"C++ compile result in {turn}th turn:\n{cpp_compile_result}")

        break_outer_loop = False

        if not cuda_p_f:  # Modify CUDA code
            if b"undefined reference to" in cuda_stderr or b"No such file or directory" in cuda_stderr:
                modification_prompt = combine_header_files_cuda.format(compile_result=f"CUDA Compile Stderr: {cuda_stderr}")
            else:
                modification_prompt = cu_ct_further_modification.format(cuda_compile_result=cuda_compile_result)

            try:
                fur_modification(history, ser_messages, modification_prompt)
            except:
                break

            content = history[-1]["content"]
            logging.info(f"CUDA GPT answer:\n{content}")
            cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

        if not cpp_p_f:  # Modify C++ code
            if b"undefined reference to" in cpp_stderr or b"No such file or directory" in cpp_stderr:
                modification_prompt = combine_header_files_cpp.format(compile_result=f"C++ Compile Stderr: {cpp_stderr}")
            elif b'missing terminating " character' in cpp_stderr:
                modification_prompt = missing_terminating.format(cpp_compile_result=cpp_compile_result)
            else:
                modification_prompt = ft_cf_further_modification.format(cpp_compile_result=cpp_compile_result)

            try:
                fur_modification(history, ser_messages, modification_prompt)
            except:
                break

            content = history[-1]["content"]
            logging.info(f"C++ GPT answer:\n{content}")
            cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

        if cuda_p_f and cpp_p_f:
            decision_prompt = cu_ct_further_check.format(
                cuda_compile_result=cuda_compile_result,
                cpp_compile_result=cpp_compile_result
            )
            try:
                fur_modification(history, ser_messages, decision_prompt)
            except:
                break

            content = history[-1]["content"]
            logging.info(f"cu_ct gpt answer:\n{content}")
            cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

            for end_check in range(2):
                str_y_n = history[-1]["content"]
                if "yes" in str_y_n.lower():
                    end_prompt = end_prompt_
                    fur_modification(history, ser_messages, end_prompt)
                    content = history[-1]["content"]
                    logging.info(f"yes\n{content}")
                    break_outer_loop = True

                    cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

                    with open(f'F2C-Translator/data/final_pairs/cuda_code{idx}.cu', 'w') as file:
                        file.write(cuda_code_exe)
                    with open(f'F2C-Translator/data/final_pairs/cpp_code{idx}.cpp', 'w') as file:
                        file.write(cpp_code_exe)
                    break
                elif "no" in str_y_n.lower():
                    fur_modification(history, ser_messages, further_modification_)
                    content = history[-1]["content"]
                    logging.info(f"no\n{content}")
                    cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)
                    break
                else:
                    fur_modification(history, ser_messages, clear_prompt_)
                    content = history[-1]["content"]
                    logging.info(f"unclear\n{content}")
                    cuda_code_exe, cpp_code_exe = update_code_from_history(cuda_code_exe, cpp_code_exe, history)

        if break_outer_loop:
            break
    return history,break_outer_loop


# def Ai_chat_with_Ai(key,fortran_code, max_tokens, gpt_model = DEFAULT_MODEL_ID, turns_limitation = 3, idx = 0):
#     """
#     Simulate a conversation between a questioner and a solver using an AI model to translate Fortran code
#     to C++ and generate unit tests, handling errors and updates iteratively.

#     Args:
#         key (str): API key for accessing the AI model.
#         fortran_code (str): The Fortran code to be translated and tested.
#         max_tokens (int): Maximum number of tokens for AI responses.
#         gpt_model (str): Model name for the AI.
#         turns_limitation (int): Number of modification turns to perform (default is 3).

#     Returns:
#         tuple: History of the conversation and a flag indicating if the process should stop.
#     """

#     qer_messages = []
#     ser_messages = []
#     history = []
    
#     # define the role of questioner
#     m_qer = {
#         "role": "system",
#         "content": Instruction_qer
#     }    
#     qer_messages.append(m_qer) # system role defined
    
#     # Start the conversation
#     m_qer = {
#         "role": "user",
#         "content": q_ask_s_translation.format(fortran_code = fortran_code)
#     }  
#     qer_messages.append(m_qer) # user provides the question
    
#     # Questioner asks for the C++ translation from Fortran
#     #-----------------------------------
#     m_qer_gpt = generate_from_GPT(key,prompts=qer_messages, 
#                                 max_tokens=max_tokens, 
#                                 model=gpt_model, 
#                                 n=1)[0]["message"]
#     qer_answer = m_qer_gpt["content"]
#     qer_messages.append(m_qer_gpt)
#     logging.info(f"qer (questioner) asked for the C++ translation:\n{qer_answer}")
    
#     # Solver generates the C++ translation
#     m_ser = {
#         "role": "user",
#         "content": f"{qer_answer}"
#     }
#     ser_messages.append(m_ser)
#     history.append(m_ser)
#     m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
#                                 max_tokens=max_tokens, 
#                                 model=gpt_model, 
#                                 n=1)[0]["message"]
#     ser_answer = m_ser_gpt["content"]
#     logging.info(f"Solver generated the C++ translation:\n{ser_answer}")
#     ser_messages.append(m_ser_gpt)
#     m_his = {
#         "role": "assistant",
#         "content": f"{ser_answer}"
#     }
#     history.append(m_his)  
    
#     # Questioner asks for the unit test
#     #-----------------------------------
#     m_qer = {
#         "role": "user",
#         "content": q_ask_s_unit_test.format(ser_answer = ser_answer)
#     }  
#     qer_messages.append(m_qer)  
#     m_qer_gpt = generate_from_GPT(key,prompts=qer_messages, 
#                                 max_tokens=max_tokens, 
#                                 model=gpt_model, 
#                                 n=1)[0]["message"]
#     qer_answer = m_qer_gpt["content"] 
#     logging.info(f"Questioner asks for the unit test:\n{qer_answer}")   
#     qer_messages.append(m_qer_gpt)
    
#     # Solver generates the unit test
#     m_ser = {
#         "role": "user",
#         "content": f"{qer_answer}"
#     }
#     ser_messages.append(m_ser)
#     history.append(m_ser)
#     m_ser_gpt = generate_from_GPT(key,prompts=ser_messages, 
#                                 max_tokens=max_tokens, 
#                                 model=gpt_model, 
#                                 n=1)[0]["message"]
#     ser_answer = m_ser_gpt["content"]    
#     logging.info(f"Solver generate the unit test:\n{ser_answer}")   
#     ser_messages_init = ser_messages
#     ser_messages.append(m_ser_gpt)
#     m_his = {
#         "role": "assistant",
#         "content": f"{ser_answer}"
#     }
#     history.append(m_his)  
    
#     """
#     Compile, execute, and repair the pair of unit test codes
#     """
#     #-----------------------------------
#     f_code_exe = ''
#     c_code_exe = ''
#     f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)    
    
#     for turn in range(turns_limitation):
#         logging.info(f"Runing modification {turn}th turn")
#         # Initialize the solver message to avoid the potential impact from previous wrong answers
#         Init_solver = Init_solver_prompt.format(fortran_code = f_code_exe, cpp_code = c_code_exe)
#         ser_message_unit_test = {
#         "role": "assistant",
#         "content": f"{Init_solver}"
#         }
#         ser_messages_init_copy = ser_messages_init.copy()
#         ser_messages_init_copy.append(ser_message_unit_test)
#         ser_messages = ser_messages_init_copy
#         # Extract compile and execute fortran and cpp unit test
#         fortran_folder = '../sandbox/fortran'
#         cpp_folder = '../sandbox/cpp'
        
#         os.makedirs(fortran_folder, exist_ok=True)
#         os.makedirs(cpp_folder, exist_ok=True)
#         logging.info("fortran code that need to be executed:\n {f_code_exe}")    
#         logging.info("c++ code that need to be executed:\n{c_code_exe}")  
#         fortran_stdout, fortran_stderr, fortran_p_f, cpp_stdout, cpp_stderr, cpp_p_f = run_codes(fortran_folder, f_code_exe, cpp_folder, c_code_exe)
   
#         fortran_compile_result = f"Fortran Stdout: {fortran_stdout}\nFortran Stderr: {fortran_stderr}"
#         cpp_compile_result = f"C++ Stdout: {cpp_stdout}\nC++ Stderr: {cpp_stderr}"   
#         logging.info(f"fortran compile result in {turn}th turn:\n{fortran_compile_result}")
#         logging.info(f"cpp compile result in {turn}th turn:\n{cpp_compile_result}")
        
#         # further modification / end
#         break_outer_loop = False
#         if fortran_p_f == False: # Modify fortran
            
#             # Missing header files error
#             if b"undefined reference to" in fortran_stderr or b"No such file or directory" in fortran_stderr:
#                 modification_prompt = combine_header_files_fortran.format(compile_result = f"Fortran Compile Stderr:{fortran_stderr}")
#                 try:
#                     fur_modification(history, 
#                             ser_messages, 
#                             modification_prompt)
#                 except:
#                     break
#                 content=history[-1]["content"];
#                 logging.info("Add fortran head file:\n{content}") 
#                 f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)
                
#             # Other errors
#             else:
#                 modification_prompt = ff_ct_further_modification.format(fortran_compile_result = fortran_compile_result)
#                 try:
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         modification_prompt)   
#                 except:
#                     break 
#                 content=history[-1]["content"];
#                 logging.info("ff_ct gpt answer:\n{content}")      
#                 f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)        
        
#         if cpp_p_f == False: # Modify cpp
            
#             # Missing header files error
#             if b"undefined reference to" in cpp_stderr or b"No such file or directory" in cpp_stderr:
#                 modification_prompt = combine_header_files_cpp.format(compile_result = f"C++ Compile Stderr:{cpp_stderr}")
#                 try:
#                     fur_modification(history, 
#                             ser_messages, 
#                             modification_prompt)
#                 except:
#                     break 
#                 content = history[-1]["content"]
#                 logging.info("Add c++ head file:\n{content}") 
#                 f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)  
            
#             #  Missing terminating error
#             elif b'missing terminating " character' in cpp_stderr:         
#                 modification_prompt = missing_terminating.format(cpp_compile_result = cpp_compile_result)
#                 try:
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         modification_prompt)   
#                 except:
#                     break                  
#                 content = history[-1]["content"]
#                 logging.info("Missing terminating:\n{content}")     
#                 f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)   
                 
#             # Other errors
#             else:
#                 modification_prompt = ft_cf_further_modification.format(cpp_compile_result = cpp_compile_result)
#                 try:
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         modification_prompt)     
#                 except:
#                     break                 
#                 content =  history[-1]["content"]
#                 logging.info("ft_cf gpt answer:\n{content}")     
#                 f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                               
                 
#         if fortran_p_f == True and cpp_p_f == True:
#             decision_prompt = ft_ct_further_check.format(fortran_compile_result = fortran_compile_result,
#                                                          cpp_compile_result = cpp_compile_result) 
#             try:
#                 fur_modification(history, 
#                                     ser_messages, 
#                                     decision_prompt)  
#             except:
#                 break
#             content = history[-1]["content"] 
#             logging.info("ft_ct gpt answer:\n{content}")
#             f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)              
#             for end_check in range(2):
#                 Str_y_n = history[-1]["content"]    
#                 if "yes" in Str_y_n.lower():
#                     end_prompt = end_prompt_
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         end_prompt)
#                     content = history[-1]["content"]
#                     logging.info("yes\n{content}")
#                     break_outer_loop = True # break outer layer
#                     f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history) 
#                     # save the code to readable file with different names
#                     with open(f'F2C-Translator/data/final_pairs/fortran_code{idx}.f90', 'w') as file:
#                         file.write(f_code_exe)
#                     with open(f'F2C-Translator/data/final_pairs/cpp_code{idx}.cpp', 'w') as file:
#                         file.write(c_code_exe)                 
#                     break
#                 elif "no" in Str_y_n.lower():
#                     further_modification = further_modification_
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         further_modification)
#                     content = history[-1]["content"]
#                     logging.info("no\n{content}")
#                     f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                     
#                     break
#                 else:
#                     clear_prompt = clear_prompt_       
#                     fur_modification(history, 
#                                         ser_messages, 
#                                         clear_prompt)                             
#                     content = history[-1]["content"]
#                     logging.info("unclear\n{content}")
#                     f_code_exe,c_code_exe = update_code_from_history(f_code_exe, c_code_exe, history)                 
#         if break_outer_loop:
#             break
                
#     return history,break_outer_loop

def generate_data(key, input_dataset, output_file, gpt_model=DEFAULT_MODEL_ID):
    """
    Processes a dataset of CUDA codes to generate cleaned and translated C++ code along with explanations.
    The results are saved to an output file.

    Args:
        key (str): API key for accessing the AI model.
        input_dataset (dict): Dictionary containing CUDA code snippets.
        output_file (str): Path to the output file where results will be saved.
        gpt_model (str): Name of the GPT model to be used.

    Returns:
        None
    """    
    dialogues = []

    for idx in range(len(input_dataset['code'])):
        logging.info(f"Working on the {idx}th code...")
        cuda_code = input_dataset['code'][idx]

        encoding = tiktoken.encoding_for_model(gpt_model)
        token_count = len(encoding.encode(cuda_code + "\n", disallowed_special=()))

        if token_count < 3700:
            max_tokens = 256 + token_count

            # Step 1: Delete comments using LLM
            cuda_wo_com_prompt = delete_comments.format(Cuda_Code=cuda_code)
            cuda_wo_com = generate_str_answer_gpt(cuda_wo_com_prompt, max_tokens)
            cuda_wo_com = cuda_wo_com.encode().decode('unicode_escape', 'replace')

            logging.info(f"cuda_wo_com:\n{cuda_wo_com}")
            token_count = len(encoding.encode(cuda_wo_com, disallowed_special=()))
            logging.info(f"cuda_wo_com token_count: {token_count}")

            if token_count < 600:
                cuda_start = cuda_wo_com.find("```cuda") + 7
                if cuda_start == 6:
                    logging.info("Did not find the CUDA code block!")
                    continue
                else:
                    cuda_end = cuda_wo_com.find("```", cuda_start)
                    cuda_wo_com = cuda_wo_com[cuda_start:cuda_end].strip()

                try:
                    cuda_wo_com
                except NameError as e:
                    logging.info(f"Did not find the CUDA code!\n{str(e)}")
                    continue 

                # Step 2: Remove non-executable or unsupported code
                skip_code = False

                keywords_to_remove = ['fopen', 'fscanf', 'fprintf', 'fread', 'fwrite']
                if any(keyword in cuda_wo_com for keyword in keywords_to_remove):
                    skip_code = True
                    logging.info("This CUDA code contains external file operations, it will be skipped!")

                if_contain_ext = if_contain_ext_prompt.format(Cuda_Code=cuda_wo_com)
                if_contain_ext = generate_str_answer_gpt(if_contain_ext, max_tokens)
                if_contain_ext = if_contain_ext.encode().decode('unicode_escape')    
                if "no" not in if_contain_ext.lower():      
                    skip_code = True             
                    logging.info("This CUDA code contains undefined external functions, it will be skipped!")          

                # Step 3: Get translated C++ and explanation via dialogue
                if not skip_code:
                    try:
                        history, break_outer_loop = Ai_chat_with_Ai(
                            key=key,
                            cuda_code=cuda_wo_com,
                            max_tokens=4096,
                            gpt_model=gpt_model,
                            turns_limitation=7,
                            idx=idx
                        )
                    except Exception as e:
                        logging.info(f"Skip due to error!\n{str(e)}")
                        continue 
                    if break_outer_loop:
                        add_to_json(history, output_file)


# def generate_data(key, input_dataset, output_file, gpt_model=DEFAULT_MODEL_ID):
#     """
#     Processes a dataset of Fortran codes to generate cleaned and translated code along with explanations.
#     The results are saved to an output file.

#     Args:
#         key (str): API key for accessing the AI model.
#         input_dataset (dict): Dictionary containing Fortran code snippets.
#         output_file (str): Path to the output file where results will be saved.
#         gpt_model (str): Name of the GPT model to be used.

#     Returns:
#         None
#     """    
#     # initialize the list for holding each row of the dataset
#     dialogues = []
    
#     # select source fortran codes from a dataset
#     for idx in range(len(input_dataset['code'])):
#         logging.info(f"Working on the {idx}th code...")
#         fortran_code = input_dataset['code'][idx]
        
#         # Count the length of the input tokens
#         encoding = tiktoken.encoding_for_model(DEFAULT_MODEL_ID)
#         token_count = len(encoding.encode(fortran_code + "\n",disallowed_special=()))
        
#         # set a upper limit of the length of the input prompt and generate the answer
#         if token_count < 3700:
#             max_tokens= 256 + token_count
            
#             # Step 1: delete the comments of the source fortran code
#             fortran_wo_com = delete_comments.format(Fortran_Code = fortran_code)
#             fortran_wo_com = generate_str_answer_gpt(fortran_wo_com, max_tokens)
#             fortran_wo_com = fortran_wo_com.encode().decode('unicode_escape','replace')
#             # fortran_wo_com = remove_fortran_comments_fixed(fortran_code) 
            
#             logging.info(f"fortran_wo_com:\n{fortran_wo_com}")
#             encoding = tiktoken.encoding_for_model(DEFAULT_MODEL_ID)
#             token_count = len(encoding.encode(fortran_wo_com,disallowed_special=()))     
#             logging.info(f"fortran_wo_com tokenn_count:\{token_count}")
#             # control the length
#             if token_count < 600:     
#                 fortran_start = fortran_wo_com.find("```fortran") + 10
#                 if fortran_start == 9:
#                     logging.info("Did not find the fortran code!")
#                     continue
#                 else:
#                     fortran_end = fortran_wo_com.find("```", fortran_start)
#                     fortran_wo_com = fortran_wo_com[fortran_start:fortran_end].strip()
#                 try:
#                     fortran_wo_com
#                 except NameError as e:
#                     logging.info("Did not find the fortran code!\n{str(e)}")
#                     continue 
                
#                 # Step 2: Remove non-executable code 
#                 skip_code = False
                
#                 # Remove code that contains external file reading operations
#                 keywords_to_remove = ['OPEN', 'READ', 'WRITE', 'CLOSE']
#                 if any(keyword in fortran_wo_com for keyword in keywords_to_remove):
#                     skip_code = True
#                     logging.info("This fortran code contains external file reading operations, it will be skipped!")

#                 # Remove code that contains operations for user input
#                 keywords_to_remove = ['GET_ENVIRONMENT_VARIABLE', 
#                                       'READ', 
#                                       'GET_COMMAND_ARGUMENT', 
#                                       'IARGC',
#                                       'GETARG']
                             
#                 if any(keyword in fortran_wo_com.upper() for keyword in keywords_to_remove):
#                     skip_code = True
#                     logging.info("This Fortran code contains operations for user input, it will be skipped!")    
                    
#                 # Remove Fortran code containing undefined external functions
#                 if_contain_ext = if_contain_ext_prompt.format(Fortran_Code = fortran_wo_com)
#                 if_contain_ext = generate_str_answer_gpt(if_contain_ext, max_tokens)
#                 if_contain_ext = if_contain_ext.encode().decode('unicode_escape')    
#                 if "no" not in if_contain_ext.lower():      
#                     skip_code = True             
#                     logging.info("This Fortran code contains undefined external functions, it will be skipped!")          
                                               
#                 # Step 3: get function of the code; translated cpp code and explanation    
#                 if skip_code == False:
#                     try:
#                         history,break_outer_loop = Ai_chat_with_Ai(key,
#                                                 fortran_wo_com, 
#                                                 max_tokens = 4096, 
#                                                 gpt_model = gpt_model,
#                                                 turns_limitation = 7,
#                                                 idx = idx)
#                     except:
#                         logging.info("Skip!\n{str(e)}")
#                         continue 
#                     if break_outer_loop:
#                         add_to_json(history, output_file)
            

    
    
# def inference(eval_csv_path, model_name_or_path, device_num=3):
#     with open(eval_csv_path, 'r') as file:
#         csv_reader = csv.reader(file)
#         next(csv_reader, None)  
#         row_count = sum(1 for row in csv_reader)
    
#     # read eval_data from csv file
#     eval_data = pd.read_csv(eval_csv_path)
#     res=[-1]*row_count

#     tokenizer, model = load_local_model(model_name_or_path, device_num=device_num)
#     if tokenizer.pad_token is None:
#         tokenizer.pad_token = tokenizer.eos_token

#     for i in range(row_count):
#         # read eval data: fortran code and cpp code
#         fortran_code = eval_data['fortran'][i]
#         cpp_code = eval_data['cpp'][i]

#         # get model output
#         input_prompt_local = "Translate the following Fortran code to cpp " + fortran_code
#         try:
#             predicted_answer = generate_from_local_model(input_prompt_local, 2*len(input_prompt_local), tokenizer, model, device_num, n=1, max_prompt_length=1024)[0]                
#             logging.info("predicted_answer",predicted_answer) # Print the generated data
            
#             # assert: compiler
#             yes_or_no_compiler, reason = check_by_compiler(predicted_answer)
#             if yes_or_no_compiler == True:
#                 # assert GPT4
#                 messages = []
#                 message = {
#                 "role": "user",
#                 "content": Asserter_Y_N.format(Fortran_Code=fortran_code, Cpp_Code=predicted_answer)}
#                 messages.append(message)
#                 yes_or_no, reason = check_code_translation(i,messages)
#                 if yes_or_no == True:
#                     res[i] = 1
#                 else:
#                     res[i] = 0
#             else:
#                 res[i] = 0
#         except Exception as e:
#             logging.info(f"An error occurred: {e}")
#     logging.info("RATIO:", res.count(1)/(res.count(1)+res.count(0)))
#     return res.count(1)/(res.count(1)+res.count(0))

if __name__ == "__main__":
    key = get_openai_api_key() # Obtain your OpenAI Key from an environment variable named OPENAI_API_KEY
    
    # You can also use other datasets
#The repository for codeparrot/github-code contains custom code which must be executed to correctly load the dataset. 
    Fortran_dataset = load_dataset("codeparrot/github-code", "FORTRAN-all", trust_remote_code=True)
#    data = Fortran_dataset["train"][78000:85000] # 7000 data samples here
    data = Fortran_dataset["train"][78000:78050] # debug smaller sample size: 50 only
    openai_model_id = DEFAULT_MODEL_ID # default gpt-4o : over 10x expensive than 4o-mini

    output_file = "gpt-4o-mini-100-samples.json" # Output Json file
    generate_data(key, data, output_file, gpt_model=openai_model_id) # May need to change, default gpt-4o
    
