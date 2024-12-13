! myFunction.f90
subroutine myFunction(f, d)
  use iso_c_binding, only: c_size_t
  implicit none
  real, intent(inout) :: f
  integer(c_size_t), intent(in) :: d

  write(*,*) 'f=', f, 'd=', d
end subroutine myFunction