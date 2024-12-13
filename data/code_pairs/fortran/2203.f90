subroutine sctovec(tp, v)
  implicit none
  real(8), intent(in) :: tp(2)
  real(8), intent(out) :: v(3)
  real(8) :: t1
  
  t1 = sin(tp(1))
  v(1) = t1 * cos(tp(2))
  v(2) = t1 * sin(tp(2))
  v(3) = cos(tp(1))
end subroutine sctovec