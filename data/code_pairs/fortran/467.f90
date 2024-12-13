module ppm_module_bem_quadrule
  implicit none
contains
  ! Single precision version of the procedure
  subroutine ppm_bem_quadrule_s(result)
    real(4) :: result
    ! Hypothetical calculation for demonstration
    result = 1.0  ! Placeholder value
  end subroutine ppm_bem_quadrule_s

  ! Double precision version of the procedure
  subroutine ppm_bem_quadrule_d(result)
    real(8) :: result
    ! Hypothetical calculation for demonstration
    result = 1.0d0  ! Placeholder value
  end subroutine ppm_bem_quadrule_d
end module ppm_module_bem_quadrule