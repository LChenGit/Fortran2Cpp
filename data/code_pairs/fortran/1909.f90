program chk_alloc_string
    implicit none
    character(len=:), dimension(:), allocatable :: strings
    character(20) :: buffer
    integer :: i

    allocate(character(len=10) :: strings(5))
    strings = ["A   ", "C   ", "ABCD", "V   ", "zzzz"]

    ! The checks are embedded within the test program below.
    ! The output formatting and checks would typically occur here or in a subroutine.

    write(buffer, "(5a4)") strings
    print *, buffer
end program chk_alloc_string