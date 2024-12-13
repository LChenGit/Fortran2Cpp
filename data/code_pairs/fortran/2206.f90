program main_fortran_code
    implicit none
    integer :: a1d1(10), tmp(10)
    integer :: me, nerr, ival, i

    ! For testing, simulate a single "node" environment
    me = 1

    ! Initialize arrays
    do i = 1, 10
        a1d1(i) = i * me + max(-1, 0)
    enddo
    tmp = 0

    ! Mimic parallel assignment logic
    tmp(2:6) = a1d1(2:6)

    nerr = 0
    do i = 1, 10
        if (i >= 2 .and. i <= 6) then
            ival = i * 3
        else
            ival = 0
        endif
        if (tmp(i) /= ival) then
            print *, "tmp(", i, ")=", tmp(i), " should be ", ival
            nerr = nerr + 1
        endif
    enddo

    if (nerr == 0) then
        print *, "(", me, ") OK"
    else
        print *, "(", me, ") number of NGs: ", nerr
    endif
end program main_fortran_code