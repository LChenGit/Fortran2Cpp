subroutine calcrhoelcomp(nef, vel, shcon, ielmatf, ntmat_, mi, nefa, nefb)
    implicit none
    integer :: nef, i, imat, ntmat_, mi(*), ielmatf(mi(3), *), nefa, nefb
    real(8) :: t1l, vel(nef, 0:7), shcon(0:3, ntmat_, *)

    do i = nefa, nefb
        t1l = vel(i, 0)
        imat = ielmatf(1, i)
        vel(i, 5) = vel(i, 4) / (shcon(3, 1, imat) * t1l)
    end do
end subroutine calcrhoelcomp