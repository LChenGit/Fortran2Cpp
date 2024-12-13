module lessToxicModule
    implicit none
contains
    subroutine less_toxic(a, b)
        integer, intent(in) :: a, b
        print *, "less_toxic called with", a, "and", b
    end subroutine less_toxic
end module lessToxicModule

program testProgram
    use lessToxicModule
    implicit none

    call test_less_toxic

contains

    subroutine test_less_toxic()
        implicit none

        call less_toxic(1, 2)
        call less_toxic(3, 4)
        call less_toxic(5, 6)
    end subroutine test_less_toxic

end program testProgram