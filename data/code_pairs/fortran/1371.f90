! fm013.f90
module fm013_mod
  implicit none
contains
  subroutine fm013(iczero, ivdele)
    integer, intent(in) :: iczero
    integer, intent(inout) :: ivdele
    ! Emulating the arithmetic IF statement
    if (iczero == 0) then
      ivdele = ivdele + 1
    end if
  end subroutine fm013
end module fm013_mod