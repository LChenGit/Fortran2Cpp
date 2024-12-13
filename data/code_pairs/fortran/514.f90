module gsw_calculations
    implicit none
    integer, parameter :: r8 = selected_real_kind(15)

contains

    ! Placeholder functions for external dependencies
    function gsw_alpha_on_beta(sa, ct, p) result(aob)
        real(r8), intent(in) :: sa, ct, p
        real(r8) :: aob
        aob = 1.0
    end function

    function gsw_rho(sa, ct, p) result(density)
        real(r8), intent(in) :: sa, ct, p
        real(r8) :: density
        density = 1025.0
    end function

    subroutine gsw_specvol_first_derivatives(sa, ct, p, v_sa, v_ct)
        real(r8), intent(in) :: sa, ct, p
        real(r8), intent(out) :: v_sa, v_ct
        v_sa = 0.1
        v_ct = 0.1
    end subroutine

    subroutine gsw_specvol_second_derivatives(sa, ct, p, v_sa_sa, v_sa_ct, v_ct_ct)
        real(r8), intent(in) :: sa, ct, p
        real(r8), intent(out) :: v_sa_sa, v_sa_ct, v_ct_ct
        v_sa_sa = 0.01
        v_sa_ct = 0.01
        v_ct_ct = 0.01
    end subroutine

    function gsw_cabbeling(sa, ct, p) result(cabbeling_coefficient)
        real(r8), intent(in) :: sa, ct, p
        real(r8) :: cabbeling_coefficient
        real(r8) :: alpha_ct, alpha_on_beta, alpha_sa, beta_sa, rho
        real(r8) :: v_sa, v_ct, v_sa_sa, v_sa_ct, v_ct_ct

        call gsw_specvol_first_derivatives(sa, ct, p, v_sa, v_ct)
        call gsw_specvol_second_derivatives(sa, ct, p, v_sa_sa, v_sa_ct, v_ct_ct)

        rho = gsw_rho(sa, ct, p)

        alpha_ct = rho * (v_ct_ct - rho * v_ct * v_ct)
        alpha_sa = rho * (v_sa_ct - rho * v_sa * v_ct)
        beta_sa = -rho * (v_sa_sa - rho * v_sa * v_sa)

        alpha_on_beta = gsw_alpha_on_beta(sa, ct, p)

        cabbeling_coefficient = alpha_ct + alpha_on_beta * (2.0 * alpha_sa - alpha_on_beta * beta_sa)
    end function

end module gsw_calculations

program test_gsw_cabbeling
    use gsw_calculations
    implicit none

    real(r8) :: sa, ct, p
    real(r8) :: cabbeling_coefficient

    sa = 35.0_r8
    ct = 10.0_r8
    p = 1000.0_r8

    cabbeling_coefficient = gsw_cabbeling(sa, ct, p)

    print *, "Cabbeling coefficient: ", cabbeling_coefficient
end program test_gsw_cabbeling