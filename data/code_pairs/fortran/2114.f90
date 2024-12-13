program test_add_integers
    implicit none
    integer :: result

    call add_integers(5, 10, result)
    print *, "The result of adding 5 and 10 is ", result

contains

    subroutine add_integers(a, b, result)
        implicit none
        integer, intent(in) :: a, b
        integer, intent(out) :: result

        result = a + b
    end subroutine add_integers

end program test_add_integers