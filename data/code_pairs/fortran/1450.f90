subroutine pbm_cut(ks, kstart, kend, nthds)
    integer, intent(out) :: ks(2, *)
    integer, intent(in) :: kstart, kend, nthds
    integer :: kend0, kstart0, ithds, nn, nblk

    kend0 = kend
    kstart0 = kstart
    ithds = 0

    do while (ithds < nthds-1)
        nn = kend0 - kstart0 + 1
        nblk = nn / (nthds - ithds)
        if (nblk < 0) nblk = 0
        if (mod(nblk, 2) == 1) nblk = nblk + 1

        ks(1, ithds+1) = kstart0
        ks(2, ithds+1) = kstart0 + nblk - 1
        kstart0 = kstart0 + nblk
        ithds = ithds + 1
    end do

    nn = kend0 - kstart0 + 1
    nblk = nn
    if (nblk < 0) nblk = 0
    ks(1, ithds+1) = kstart0
    ks(2, ithds+1) = kstart0 + nblk - 1
end subroutine pbm_cut