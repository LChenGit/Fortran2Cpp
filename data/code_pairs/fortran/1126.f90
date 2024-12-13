! snafu_module.f90
module snafu_mod
  implicit none
contains
  subroutine snafu(i, c1, c2)
    integer, intent(in) :: i
    character(len=:), allocatable :: c1, c2
    allocate(character(len=i) :: c1, c2)
    c1 = ""
    c2 = ""
  end subroutine snafu
end module snafu_mod