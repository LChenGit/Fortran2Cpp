program procedure_pointer_test
    implicit none

    ! Define the abstract interface
    abstract interface
        function my_function()
            import
            real(8) :: my_function
        end function my_function
    end interface

    ! Declare the procedure pointer
    procedure(my_function), pointer :: my_proc => null()

    real(8) :: result

    ! Unit test procedure
    call setup()  ! Call the setup to assign the procedure pointer

    ! Test if the procedure pointer is associated
    if (associated(my_proc)) then
        print *, "Procedure pointer is associated. Performing test..."
        result = my_proc()
        if (result == 0.0d0) then
            print *, "Test passed: Function returned 0.0"
        else
            print *, "Test failed: Function returned", result, "instead of 0.0"
        end if
    else
        print *, "Test failed: Procedure pointer is not associated"
    end if

contains

    ! Setup subroutine to assign the procedure pointer
    subroutine setup()
        ! Assign the function to the procedure pointer
        my_proc => my_external_function
    end subroutine setup

    ! External function implementation
    function my_external_function()
        real(8) :: my_external_function
        my_external_function = 0.0d0
    end function my_external_function

end program procedure_pointer_test