program implicit_input_output
    integer :: i, j
    real :: a(2, 3)

    ! Fill the matrix
    do i = 1, 2
        do j = 1, 3
            a(i, j) = 10*i + j
        end do
    end do

    ! Print the entire matrix
    do j = 1, 3
        do i = 1, 2
            print *, a(i, j),
        end do
    end do
    print *, "" ! New line

    ! Print the first row
    do j = 1, 3
        print *, a(1, j),
    end do
    print *, "" ! New line

    ! Print the first column
    do i = 1, 2
        print *, a(i, 1),
    end do
    print *, "" ! New line

end program implicit_input_output