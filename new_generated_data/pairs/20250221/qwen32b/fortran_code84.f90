program main_program
    implicit none
    integer :: result

    ! Declare the function interface explicitly
    interface
        integer function add_numbers(a, b)
            integer, intent(in) :: a, b
        end function add_numbers
    end interface

    ! Example function call
    result = add_numbers(5, 3)
    print *, "Result of addition:", result

    ! Example subroutine call
    call display_message("Hello, Fortran!")

end program main_program

! Example function to add two integers
integer function add_numbers(a, b)
    integer, intent(in) :: a, b
    add_numbers = a + b
end function add_numbers

! Example subroutine to display a message
subroutine display_message(message)
    character(len=*), intent(in) :: message
    print *, message
end subroutine display_message