! Save as darnan.f90
subroutine DARNAN(NUM, INFO)
  implicit none
  real(8), intent(in) :: NUM
  integer, intent(inout) :: INFO

  INFO = 0
  if (NUM .NE. NUM) then
    INFO = 1
  end if
end subroutine DARNAN