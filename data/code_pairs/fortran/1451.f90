! main.f90
program test
    implicit none
    character(50) :: buffer
    real(4) :: real_4
    real(8) :: real_8
    integer :: len

    character(*), parameter :: fmt = "(A, F8.6, A)"

    real_4 = 4.18
    write(buffer, fmt) ':',real_4,':'
    print *,buffer

    real_8 = 4.18
    write(buffer, fmt) ':',real_8,':'
    print *,buffer
end program test