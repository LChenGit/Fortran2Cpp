module mod_class_fitness_calculator_exit_code
    implicit none
    
    type, public :: class_fitness_calculator_exit_code
        integer :: SUCCESS = 0
        integer :: FAIL_AND_GIVE_UP = 1
        integer :: FAIL_AND_TRY_AGAIN = 2
    end type class_fitness_calculator_exit_code
end module mod_class_fitness_calculator_exit_code