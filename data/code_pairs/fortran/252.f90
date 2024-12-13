module init_conds_module
    implicit none
    contains

    subroutine init_conds(x, y, z, rho, ux, uy, uz, p)
        double precision, intent(in) :: x, y, z
        double precision, intent(out) :: rho, ux, uy, uz, p

        uz = 0.0d0

        if ((x >= 0.25d0) .and. (x <= 0.75d0) .and. (y >= 0.25d0) .and. (y <= 0.75d0)) then
            p = 2.5d0
            rho = 4.0d0
        else
            p = 2.5d0
            rho = 1.0d0
        endif

        ux = 0.5d0
        uy = 0.5d0
    end subroutine init_conds

end module init_conds_module