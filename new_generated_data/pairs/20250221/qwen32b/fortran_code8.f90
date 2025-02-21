module MExample
    implicit none
    type :: TExample
    contains
        procedure :: present
    end type TExample

    contains

    function present(this) result(success)
        class(TExample) :: this
        integer :: success
        success = 0  ! Indicate success
        print *, "Present method executed successfully."
    end function present
end module MExample

program TestProgram
    use MExample
    implicit none

    type(TExample) :: example
    integer :: result

    result = example%present()

    if (result /= 0) then
        print *, "Test failed: present method did not execute successfully."
        call exit(1)
    end if

    print *, "Test passed: present method executed successfully."
end program TestProgram