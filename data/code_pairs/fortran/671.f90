program test_matrices
    implicit none
    real, dimension(3,3), parameter :: a = reshape ((/(i, i = 1,9)/),(/3,3/))
    real, dimension(2,3) :: b, c
    integer :: i, j

    ! Initialize matrices b and c by slicing and reversing parts of a
    b = a(2:1:-1, :)
    c = a(3:2:-1, :)

    ! Print matrices for visual inspection (optional)
    print *, "Matrix a:"
    do i = 1, 3
        print '(*(F4.1))', a(i,:)
    end do

    print *, "Matrix b:"
    do i = 1, 2
        print '(*(F4.1))', b(i,:)
    end do

    print *, "Matrix c:"
    do i = 1, 2
        print '(*(F4.1))', c(i,:)
    end do

end program test_matrices