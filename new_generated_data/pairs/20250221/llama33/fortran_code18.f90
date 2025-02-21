program test_program
    implicit none

    integer, parameter :: N = 100
    real, dimension(N, N) :: a, b, c
    integer :: i, j

    ! Initialize arrays
    do i = 1, N
        do j = 1, N
            if (j == 0) then
                stop 'Division by zero'
            end if

            if (mod(j, 2) == 0) then
                b(i, j) = 1.0
            else
                b(i, j) = 0.5
            end if

            select case (mod(i, 4))
                case (0)
                    c(i, j) = 1.0
                case (1)
                    c(i, j) = 2.0
                case (2)
                    c(i, j) = 5.9
                case (3)
                    c(i, j) = 4.0
            end select

            a(i, j) = i + j
        end do
    end do

    ! Unit tests
    do i = 1, N
        do j = 1, N
            if (a(i, j) /= i + j) then
                stop 'Test case failed: assertion failed'
            end if

            if (b(i, j) <= 0.0) then
                stop 'Test case failed: assertion failed'
            end if

            if (c(i, j) < 1.0 .or. c(i, j) > 5.9) then
                stop 'Test case failed: assertion failed'
            end if
        end do
    end do

    print *, "All unit tests passed."

end program test_program