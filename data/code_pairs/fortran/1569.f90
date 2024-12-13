subroutine hunt(xx, n, x, jlo)
    implicit none
    double precision, dimension(n) :: xx
    integer :: n, jlo
    double precision :: x
    integer :: jhi, jm, inc
    logical :: ascnd

    ascnd = xx(n) > xx(1)
    if (jlo < 1 .or. jlo > n) then
        jlo = 1
        jhi = n + 1
    else
        inc = 1
        if ((x >= xx(jlo)) .eqv. ascnd) then
            do
                jhi = jlo + inc
                if (jhi > n) then
                    jhi = n + 1
                    exit
                elseif ((x < xx(jhi)) .eqv. ascnd) then
                    exit
                else
                    jlo = jhi
                    inc = inc * 2
                endif
            end do
        else
            do
                jhi = jlo
                jlo = jhi - inc
                if (jlo < 1) then
                    jlo = 1
                    exit
                elseif ((x >= xx(jlo)) .eqv. ascnd) then
                    exit
                else
                    jhi = jlo
                    inc = inc * 2
                endif
            end do
        endif
    endif

    do while (jhi - jlo > 1)
        jm = (jhi + jlo) / 2
        if ((x >= xx(jm)) .eqv. ascnd) then
            jlo = jm
        else
            jhi = jm
        endif
    end do
end subroutine hunt