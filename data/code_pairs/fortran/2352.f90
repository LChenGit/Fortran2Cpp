module types_mod
  implicit none
  type :: Sub
    integer :: i
  end type Sub

  type :: T
    type(Sub) :: sub
  end type T

  type :: TU
    real :: r
  end type TU
end module types_mod

subroutine sub0(u)
  use types_mod
  type(T), intent(inout) :: u
  u%sub%i = 0
end subroutine sub0

subroutine sub1()
  use types_mod
  type(T) :: u
  call sub0(u)
end subroutine sub1

subroutine sub2(u)
  use types_mod
  type(TU), intent(inout) :: u
  u%r = 1.0
end subroutine sub2