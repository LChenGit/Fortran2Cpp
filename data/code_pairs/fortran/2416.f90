program main
    implicit none
    integer :: status

    call main_logic(status)
    if (status /= 0) then
        print *, "Error encountered."
    else
        print *, "All tests passed successfully."
    end if
end program main

subroutine main_logic(status)
    implicit none
    integer, intent(out) :: status
    integer, parameter :: N = 10
    character(20) :: buffer
    character(len=:), allocatable :: ca(:)

    allocate(character(len=N) :: ca(3))
    ca(1) = "foo"
    ca(2) = "bar"
    ca(3) = "xyzzy"
    
    write (buffer, '(3A5)') ca(1:3)
    if (trim(buffer) .ne. "foo  bar  xyzzy") then
        status = 1
    else
        status = 0
    end if
end subroutine main_logic