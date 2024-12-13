module calculation_module
  implicit none
contains
  subroutine compute_values(i, j)
    integer, intent(inout) :: i
    integer, intent(out) :: j
    i = 0  ! Ensure i starts with a defined value for a fair comparison
    i = i + 2 + 3
    j = 1 + 2 * 3
    i = (i + 1) * 2
  end subroutine compute_values
end module calculation_module