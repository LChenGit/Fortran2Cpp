! main.f90
program testTransfer
    implicit none
    ! No direct equivalent of these operations needed in Fortran for testing
    ! Demonstrating the usage of transfer as per the original request
    print *, 'Test 1:'
    print *, transfer(sqrt([100.]), 0_1)
    print *, 'Test 2:'
    print *, transfer(achar([100]), 0_1)
end program testTransfer