! Assuming parameters.h defines npde and mtri
! parameters.h content example:
!      integer, parameter :: npde = 2, mtri = 3

subroutine scheck(y, kvec, errc, dxymin, dxy0, dxy1, dxy)
    integer, intent(in) :: kvec
    integer, intent(out) :: errc
    double precision, intent(in) :: y(npde+2, mtri), dxymin
    double precision, intent(inout) :: dxy0(mtri), dxy1(mtri), dxy(mtri)
    integer :: j
    double precision :: x0, x1, x2, y0, y1, y2

    if (kvec == 1) then
        do j = 1, mtri
            dxy1(j) = dxy(j)
        end do
    end if

    do j = 1, mtri
        x0 = y(1, j)
        y0 = y(2, j)
        x1 = y(1, j)
        y1 = y(2, j)
        x2 = y(1, j)
        y2 = y(2, j)
        dxy(j) = abs((x0 - x2) * (y1 - y0) - (x1 - x0) * (y0 - y2))
        if (dxy(j) < dxymin) then
            errc = 1
            return
        endif
    end do

    if (kvec == 0) then
        do j = 1, mtri
            dxy0(j) = dxy(j)
        end do
    end if

    errc = 0
end subroutine scheck