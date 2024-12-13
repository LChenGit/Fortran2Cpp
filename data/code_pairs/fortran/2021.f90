module gsw_mod_toolbox
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307)

contains
    function gsw_gibbs_ice(n1, n2, t, p) result(value)
        integer, intent(in) :: n1, n2
        real(dp), intent(in) :: t, p
        real(dp) :: value
        ! Dummy implementation for demonstration - replace with actual calculations
        value = t * p * 0.01_dp
    end function gsw_gibbs_ice
end module gsw_mod_toolbox

program test_gsw_alpha_wrt_t_ice
    use gsw_mod_toolbox
    implicit none
    real(dp) :: result, t, p

    ! Test case 1
    t = 263.15_dp  ! Kelvin
    p = 10.0_dp    ! Decibars
    result = gsw_alpha_wrt_t_ice(t, p)
    print *, "Test case 1: T=", t, "P=", p, "Alpha=", result

contains
    function gsw_alpha_wrt_t_ice(t, p) result(alpha)
        real(dp), intent(in) :: t, p
        real(dp) :: alpha
        alpha = gsw_gibbs_ice(1, 1, t, p) / gsw_gibbs_ice(0, 1, t, p)
    end function gsw_alpha_wrt_t_ice
end program test_gsw_alpha_wrt_t_ice