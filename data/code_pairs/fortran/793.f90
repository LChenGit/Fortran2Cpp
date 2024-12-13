! Main Program
program main
    implicit none
    integer :: status

    status = run_tests()
    if (status == 0) then
        print *, "Fortran: Test Passed"
    else
        print *, "Fortran: Test Failed with status: ", status
    endif
end program main

! Function to perform tests based on the initial problem statement
function run_tests() result(status)
    implicit none
    integer :: status
    integer :: i
    integer, parameter :: m(4,4) = reshape([ (i, i=1, 16) ], [4, 4])
    integer, parameter :: sevens = count(m == 7)
    integer, parameter :: odd(4) = count(mod(m, 2) == 1, dim=1)
    integer, parameter :: even = count(mod(m, 2) == 0)

    status = 0
    if (sevens /= 1) then
        status = 1
    else if (any(odd /= [2,2,2,2])) then
        status = 2
    else if (even /= 8) then
        status = 3
    endif
end function run_tests