program main
    implicit none
    integer :: intVar
    real :: floatVar
    character(len=10) :: strVar
    character(len=10) :: str
    integer :: num

    ! Variable declarations
    intVar = 10
    floatVar = 20.5
    strVar = 'Hello'

    ! Arithmetic operations
    intVar = intVar + 5
    floatVar = floatVar * 2.0

    ! Character to integer conversion
    str = '123'
    read(str, *) num

    ! Integer to character conversion
    write(str,'(I10)') num

end program main