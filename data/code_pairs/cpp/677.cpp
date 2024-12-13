#ifndef MOD_CLASS_FITNESS_CALCULATOR_EXIT_CODE_H
#define MOD_CLASS_FITNESS_CALCULATOR_EXIT_CODE_H

namespace mod_class_fitness_calculator_exit_code {

    struct ClassFitnessCalculatorExitCode {
        static const int SUCCESS = 0;
        static const int FAIL_AND_GIVE_UP = 1;
        static const int FAIL_AND_TRY_AGAIN = 2;
    };

} // namespace mod_class_fitness_calculator_exit_code

#endif // MOD_CLASS_FITNESS_CALCULATOR_EXIT_CODE_H