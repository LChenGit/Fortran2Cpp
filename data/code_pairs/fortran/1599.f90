! main.f90
program main
    implicit none
    integer, parameter :: n = 1024
    integer :: i
    integer, dimension(0:n-1) :: a, b, c

    do i = 0, n - 1
        a(i) = i * 2
    end do

    do i = 0, n -1
        b(i) = i * 4
    end do

    do i = 0, n - 1
        c(i) = a(i) + b(i)
    end do

    do i = 0, n - 1
        if (c(i) .ne. a(i) + b(i)) STOP 1
    end do

end program main