module propage_mod
    implicit none
contains
    subroutine propage(ip1, ip2, ier, iirai, &
                       npn, nsn, ncn, nfront, nd, nk, npar, &
                       ys, iys, dys, iseg, icel, nrai, ncel, nseg, &
                       irai, iraf, irpop, irais, isatr, isats, isatc)
        integer, intent(in) :: ip1, ip2, ier, iirai
        integer, intent(in) :: npn, nsn, ncn, nfront, nd, nk, npar
        real, intent(inout) :: ys(npar, npn, nfront)
        integer, intent(inout) :: iys(nk, npn, nfront)
        double precision, intent(inout) :: dys(nd, npn, nfront)
        integer, intent(inout) :: iseg(nsn, 6, nfront), icel(ncn, 6, nfront)
        integer, intent(inout) :: nrai(nfront), ncel(nfront), nseg(nfront)
        integer, intent(in) :: irai(3), iraf(3), irpop(3), irais(2, 3)
        integer, intent(inout) :: isatr(nfront), isats(nfront), isatc(nfront)

        if (ier /= 0) then
            iys(2, iirai, ip1) = -1
        else
            nrai(ip2) = nrai(ip2) + 1
            iys(2, nrai(ip2), ip2) = 0
            iys(2, iirai, ip1) = nrai(ip2)
            dys(1, nrai(ip2), ip2) = dys(1, iirai, ip1)
            dys(2, nrai(ip2), ip2) = dys(2, iirai, ip1)
        endif
    end subroutine propage
end module propage_mod

! Test program and subroutines omitted for brevity