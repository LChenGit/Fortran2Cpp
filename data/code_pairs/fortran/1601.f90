module B8_COM_module
    implicit none
    integer :: B8_cm
    real :: B8_nfa
    common /B8_COM_block/ B8_nfa
    equivalence (B8_nfa, B8_cm)
end module B8_COM_module

program testB8
    use B8_COM_module
    implicit none

    ! Demonstrate modifying B8_nfa affects B8_cm
    B8_nfa = 1.0
    print *, 'After setting B8_nfa to 1.0, B8_cm is:', B8_cm

    ! Demonstrate modifying B8_cm affects B8_nfa
    B8_cm = 1073741824 
    print *, 'After setting B8_cm to 1073741824, B8_nfa is:', B8_nfa
end program testB8