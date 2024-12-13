module ping_module
    implicit none
contains
    subroutine ping(s, nz, dtbuf, slim, wmin, pingdat, nping)
        real*4, intent(in) :: s(:)
        integer, intent(in) :: nz
        real*4, intent(in) :: dtbuf, slim, wmin
        real*4, intent(out) :: pingdat(3,100)
        integer, intent(out) :: nping
        logical :: inside
        real*4 :: peak, snrlim, sdown, tstart
        integer :: i, i0

        nping = 0
        peak = 0.
        inside = .false.
        snrlim = 10.0**(0.1*slim) - 1.0
        sdown = 10.0*log10(0.25*snrlim + 1.0)

        i0 = 0
        tstart = 0.0
        do i = 2, nz
            if (s(i) >= slim .and. .not. inside) then
                i0 = i
                tstart = i0 * dtbuf
                inside = .true.
                peak = 0.
            endif
            if (inside .and. s(i) > peak) then
                peak = s(i)
            endif
            if (inside .and. (s(i) < sdown .or. i == nz)) then
                if (i-i0+1 >= wmin/dtbuf) then
                    if (nping < 100) then
                        nping = nping + 1
                        pingdat(1,nping) = tstart
                        pingdat(2,nping) = dtbuf * (i - i0)
                        pingdat(3,nping) = peak
                    endif
                endif
                inside = .false.
                peak = 0.
            endif
        end do
    end subroutine ping
end module ping_module