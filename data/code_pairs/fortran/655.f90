module gsw_mod_toolbox
    use iso_fortran_env, only: real64
    implicit none
contains
    ! Placeholder for the actual gsw_t_freezing_exact function
    real(real64) function gsw_t_freezing_exact(sa, p, saturation_fraction)
        real(real64), intent(in) :: sa, p, saturation_fraction
        gsw_t_freezing_exact = -2.0_real64  ! Placeholder return value for demonstration
    end function gsw_t_freezing_exact

    ! Placeholder for the actual gsw_ct_from_t function
    real(real64) function gsw_ct_from_t(sa, t, p)
        real(real64), intent(in) :: sa, t, p
        gsw_ct_from_t = -2.5_real64  ! Placeholder return value for demonstration
    end function gsw_ct_from_t

    ! Function to compute Conservative Temperature at which seawater freezes
    real(real64) function gsw_ct_freezing_exact(sa, p, saturation_fraction)
        real(real64), intent(in) :: sa, p, saturation_fraction
        real(real64) :: t_freezing

        t_freezing = gsw_t_freezing_exact(sa, p, saturation_fraction)
        gsw_ct_freezing_exact = gsw_ct_from_t(sa, t_freezing, p)
    end function gsw_ct_freezing_exact
end module gsw_mod_toolbox

program test_gsw_ct_freezing
    use gsw_mod_toolbox
    use iso_fortran_env, only: real64
    implicit none

    real(real64) :: result, expected
    result = gsw_ct_freezing_exact(35.0_real64, 100.0_real64, 1.0_real64)
    expected = -2.5_real64

    print *, "Fortran Stdout: Test 1: ", result, "Expected: ", expected
end program test_gsw_ct_freezing