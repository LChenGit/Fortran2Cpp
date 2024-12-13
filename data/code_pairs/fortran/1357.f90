program testProgram
    implicit none

    ! This is the main program block.
    call subroutineExample()
    print *, "Result from functionExample: ", functionExample(5)

contains

    ! This subroutine prints a message.
    subroutine subroutineExample()
        print *, "Hello from subroutineExample!"
    end subroutine subroutineExample

    ! This function takes an integer input, doubles it, and returns the result.
    function functionExample(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = 2 * x
    end function functionExample

end program testProgram