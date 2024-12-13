module rpn2_module
    implicit none
contains

    subroutine rpn2_cons_update_manifold(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
        implicit none
        integer, intent(in) :: meqn, maux, idir, iface
        double precision, intent(in) :: q(meqn), auxvec_center(maux), auxvec_edge(maux)
        double precision, intent(out) :: flux(meqn)
        double precision :: urot
        integer :: m

        urot = auxvec_center(2+iface)

        do m = 1, meqn
            flux(m) = urot*q(m)
        end do
    end subroutine rpn2_cons_update_manifold

    subroutine rpn2_cons_update_zero(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
        implicit none
        integer, intent(in) :: meqn, maux, idir, iface
        double precision, intent(in) :: q(meqn), auxvec_center(maux), auxvec_edge(maux)
        double precision, intent(out) :: flux(meqn)
        integer :: m

        do m = 1, meqn
            flux(m) = 0.0
        end do
    end subroutine rpn2_cons_update_zero

end module rpn2_module