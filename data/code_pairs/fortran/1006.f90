module comrp_mod
    double precision :: ubar, vbar
end module comrp_mod

subroutine rpn2cons_update(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
    use comrp_mod
    implicit none
    integer meqn, maux, idir, m, iface
    double precision q(meqn), flux(meqn)
    double precision auxvec_center(maux), auxvec_edge(maux)
    double precision urot

    if (idir .eq. 0) then
        urot = ubar
    else
        urot = vbar
    endif

    do m = 1, meqn
        flux(m) = urot*q(m)
    enddo
end subroutine rpn2cons_update

subroutine rpn2_cons_update_zero(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
    implicit none
    integer meqn, maux, idir, iface
    double precision q(meqn), flux(meqn)
    double precision auxvec_center(maux), auxvec_edge(maux)
    integer m

    do m = 1, meqn
        flux(m) = 0.0
    enddo
end subroutine rpn2_cons_update_zero