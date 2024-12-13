module brick_tee
    implicit none
    ! Kind parameter for double precision
    integer, parameter :: DP = selected_real_kind(15, 307)
    private

    real(DP) :: c, a, rho_te, sa, TE_0
    real(DP) :: TE       

    public :: brick_tee_step_forward, brick_tee_step_backward, init_brick_tee

contains

    subroutine init_brick_tee(h_capacity, expansion_coeff, density0, ocsa, Initial_TE, thermal)
        real(DP), intent(IN) :: h_capacity, expansion_coeff, density0, ocsa, Initial_TE
        real(DP), intent(OUT) :: thermal
        
        c = h_capacity
        a = expansion_coeff
        rho_te = density0
        sa = ocsa
        TE_0 = Initial_TE

        thermal = TE_0
        TE = thermal
    end subroutine init_brick_tee

    subroutine brick_tee_step_forward(deltaH, thermal_previous, thermal_current)
        real(DP), intent(IN) :: deltaH, thermal_previous
        real(DP), intent(OUT) :: thermal_current

        thermal_current = thermal_previous + deltaH * a / (c * rho_te * rho_te * sa)
        TE = thermal_current
    end subroutine brick_tee_step_forward

    subroutine brick_tee_step_backward(deltaH, thermal_current, thermal_previous)
        real(DP), intent(IN) :: deltaH, thermal_current
        real(DP), intent(OUT) :: thermal_previous

        thermal_previous = thermal_current - deltaH * a / (c * rho_te * rho_te * sa)
    end subroutine brick_tee_step_backward

end module brick_tee