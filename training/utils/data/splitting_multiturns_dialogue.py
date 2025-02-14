"""
This Python code defines a function, `split_conversations_on_assistant`, that processes a JSON file containing conversation data, splits conversations at every message from the assistant, and writes the resulting data to an output file. Here's an explanation of the components:

### Function: `split_conversations_on_assistant`

#### Inputs:
- `input_file`: The path to the input JSON file containing conversation data.
- `output_file`: The path to save the processed JSON file with split conversations.

#### Functionality:
1. **Read JSON Data**:
   - Opens the input file, reads its content, and loads it as a Python object (`data`) using `json.load`.

2. **Prepare for Processing**:
   - Initializes an empty list, `new_data`, to store the split conversations.

3. **Process Conversations**:
   - Iterates through each conversation in the data.
   - For each conversation:
     - Extracts the `id` and `messages`.
     - Creates a `current_conversation` list to hold the messages progressively.
     - Iterates over the `messages`:
       - Adds the current message to `current_conversation`.
       - If the message's `role` is `'assistant'`, it:
         - Creates a new conversation object with the same `id` and the current state of `current_conversation`.
         - Appends this new conversation to `new_data`.

4. **Write Output**:
   - Writes the processed conversations in `new_data` to the `output_file` in a JSON format with proper indentation.

---

### Example Workflow

#### Input JSON:
```json
[
    {
        "id": "conv1",
        "messages": [
            {"role": "user", "content": "Hi"},
            {"role": "assistant", "content": "Hello!"},
            {"role": "user", "content": "How are you?"},
            {"role": "assistant", "content": "I'm good, thank you."}
        ]
    }
]
```

#### Processing Logic:
- Splits the conversation whenever the `role` is `"assistant"`. 
- After the first assistant message:
  - Stores: `[{role: "user", content: "Hi"}, {role: "assistant", content: "Hello!"}]`
- After the second assistant message:
  - Stores the entire conversation.

#### Output JSON:
```json
[
    {
        "id": "conv1",
        "messages": [
            {"role": "user", "content": "Hi"},
            {"role": "assistant", "content": "Hello!"}
        ]
    },
    {
        "id": "conv1",
        "messages": [
            {"role": "user", "content": "Hi"},
            {"role": "assistant", "content": "Hello!"},
            {"role": "user", "content": "How are you?"},
            {"role": "assistant", "content": "I'm good, thank you."}
        ]
    }
]
```

---

### Key Notes:
1. **Purpose**:
   - It creates "snapshots" of the conversation up to each assistant response, effectively capturing incremental conversation states.

2. **Deep Copy with `[:]`**:
   - Ensures a copy of `current_conversation` is appended to `new_data`, avoiding unintended modifications to previously appended items.

3. **Output**:
   - The processed data is written as a pretty-printed JSON file with `ensure_ascii=False` to preserve non-ASCII characters and `indent=4` for readability.

### Usage:
The `split_conversations_on_assistant` function can be applied to analyze incremental conversation states or debug assistant responses in a dialogue system.

"""

import json

def split_conversations_on_assistant(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as f:
        data = json.load(f)

    new_data = []

    for item in data:
        conversation_id = item['id']
        messages = item['messages']

        current_conversation = []

        for message in messages:
            current_conversation.append(message)
            
            if message['role'] == 'assistant':
                new_data.append({
                    "id": conversation_id,
                    "messages": current_conversation[:]
                })

    with open(output_file, 'w', encoding='utf-8') as f:
        json.dump(new_data, f, ensure_ascii=False, indent=4)

# Test the function
input_file = './data/F2C_dialogue_2.5K_v2_0_20.json'
output_file ='./data/F2C_dialogue_2.5K_v2_0_20_test.json'
split_conversations_on_assistant(input_file, output_file)
