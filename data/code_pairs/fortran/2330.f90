subroutine b4step2(mbc, mx, my, meqn, q, xlower, ylower, dx, dy, t, dt, maux, aux)
    implicit none
    integer, intent(in) :: mbc, mx, my, meqn, maux
    real(kind=8), intent(in) :: xlower, ylower, dx, dy, t, dt
    real(kind=8), intent(inout) :: q(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)
    real(kind=8), intent(inout) :: aux(maux, 1-mbc:mx+mbc, 1-mbc:my+mbc)

    if (t > 1.d0) then
        aux(13, :, :) = 0.d0
    endif

end subroutine b4step2