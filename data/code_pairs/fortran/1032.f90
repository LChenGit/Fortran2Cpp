module gsw_mod_kinds
    implicit none
    integer, parameter :: r8 = selected_real_kind(15, 307)
end module

module gsw_mod_toolbox
    use gsw_mod_kinds
    implicit none
contains
    subroutine gsw_enthalpy_first_derivatives(sa, ct, p, h_sa, h_ct)
        real(r8), intent(in) :: sa, ct, p
        real(r8), intent(out) :: h_sa, h_ct
        ! Placeholder calculations for demonstration
        h_sa = 0.3_r8
        h_ct = 0.4_r8
    end subroutine

    subroutine gsw_specvol_first_derivatives(sa, ct, p, vct_sa, vct_ct)
        real(r8), intent(in) :: sa, ct, p
        real(r8), intent(out) :: vct_sa, vct_ct
        ! Placeholder calculations for demonstration
        vct_sa = 0.1_r8
        vct_ct = 0.2_r8
    end subroutine
end module

module gsw_derivatives_module
    use gsw_mod_kinds
    use gsw_mod_toolbox
    implicit none
contains
    subroutine gsw_specvol_first_derivatives_wrt_enthalpy(sa, ct, p, v_sa, v_h, iflag)
        real(r8), intent(in) :: sa, ct, p
        integer, intent(in), optional :: iflag
        real(r8), intent(out), optional :: v_sa, v_h

        real(r8) :: h_ct, h_sa, rec_h_ct, vct_ct, vct_sa
        integer :: i
        logical, dimension(2) :: flags = [.true., .true.]

        if (present(iflag)) then
            do i = 1, 2
                flags(i) = ibits(iflag, i-1, 1) /= 0
            end do
        endif

        call gsw_specvol_first_derivatives(sa,ct,p,vct_sa,vct_ct)
        call gsw_enthalpy_first_derivatives(sa,ct,p,h_sa,h_ct)

        rec_h_ct = 1.0_r8 / h_ct

        if (present(v_sa) .and. flags(1)) v_sa = vct_sa - (vct_ct * h_sa) * rec_h_ct
        if (present(v_h) .and. flags(2)) v_h = vct_ct * rec_h_ct
    end subroutine
end module

program test_gsw_specvol_derivatives
    use gsw_mod_kinds
    use gsw_derivatives_module
    implicit none

    real(r8) :: sa_test, ct_test, p_test
    real(r8) :: v_sa, v_h
    integer :: iflag_test

    sa_test = 35.0_r8
    ct_test = 10.0_r8
    p_test = 1000.0_r8
    iflag_test = 3

    call gsw_specvol_first_derivatives_wrt_enthalpy(sa_test, ct_test, p_test, v_sa, v_h, iflag_test)
    print *, "Fortran Stdout: Case 1: v_sa =", v_sa, ", v_h =", v_h
end program test_gsw_specvol_derivatives