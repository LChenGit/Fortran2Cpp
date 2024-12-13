program array_operations
    implicit none
    integer :: i
    real, dimension(5) :: x, y
    real, dimension(4) :: z

    x = (/ 1., 2., 3., 4., 5. /)
    do i = 1, 5
        y(i) = i
    end do

    ! Operations demonstrated in the program
    print *, "x:", x
    print *, "y:", y
    print *, "Sum of abs(x - y):", sum(abs(x - y))
    print *, "Square root of sum of x^2:", sqrt(sum(x * x))
    print *, "Size of x:", size(x)
    z = y(2:5) - x(1:4)
    print *, "z:", z
end program array_operations