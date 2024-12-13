! TestInquire.f90
program TestInquire
    implicit none
    integer :: iUnit
    integer(8) :: iPos

    open(newunit=iUnit, file='output.txt', access='stream', status='replace')
    write(iUnit) 'TEXT'
    inquire(iUnit, pos=iPos)
    close(iUnit, status='delete')

    if (iPos /= 5) stop 1

    print *, "Fortran: Test PASSED, position is ", iPos
end program TestInquire