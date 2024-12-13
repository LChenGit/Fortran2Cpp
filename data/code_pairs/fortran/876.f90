! test_a1_d1.f90
program test_a1_d1
    implicit none
    integer :: i, j, me, nerr
    integer, dimension(7) :: a
    integer, dimension(10,3) :: b

    ! Assuming 'me' can be 1 or 2 for simplicity in this example
    me = 1
    nerr = 0
    b = -1234

    do i = 1, 7
        a(i) = i*me
    end do

    if (me == 1) then
        do i = 1, 7
            b(i, 1) = a(i)
        end do
    end if

    do j = 1, 3
        do i = 1, 10
            if (me == 1 .and. j == 1 .and. i <= 7) then
                if (b(i, j) /= i*2) then
                    nerr = nerr + 1
                end if
            else
                if (b(i, j) /= -1234) then
                    nerr = nerr + 1
                end if
            end if
        end do
    end do

    if (nerr == 0) then
        print *, 'result[', me, '] OK'
    else
        print *, 'result[', me, '] number of NGs: ', nerr
    end if
end program test_a1_d1