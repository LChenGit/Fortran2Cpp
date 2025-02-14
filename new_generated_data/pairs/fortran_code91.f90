program MatrixOperations
    implicit none
    integer, parameter :: size = 4
    integer :: TT(size, size) = 0 ! Initialize a 4x4 matrix with zeros

    integer :: i, j

    ! Modify specific elements in TT
    do i = 1, size
        do j = 1, size
            if (i == 2 .and. j == 2) then
                TT(i - 1, j - 1) = 5 ! Fortran uses 1-based indexing; we subtract 1 to work with 0-based internally
            end if
        end do
    end do

    write(*, *) "Fortran Matrix Output:"
    do i = 1, size
        write(*, *) (TT(i - 1, j), j=1, size)
    end do

end program MatrixOperations