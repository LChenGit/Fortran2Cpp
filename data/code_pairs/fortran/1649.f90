module NumericKinds
  implicit none

  integer, parameter :: &
       R_SP = selected_real_kind(6, 37), &
       R_DP = selected_real_kind(15, 307), &
       R_QP = selected_real_kind(33, 4931)

  integer, parameter :: RK = R_DP

  integer, parameter :: &
       I1B = selected_int_kind(2), &
       I2B = selected_int_kind(4), &
       I3B = selected_int_kind(9), &
       I4B = selected_int_kind(18)

  integer, parameter :: IK = I3B

contains

  elemental subroutine swapRealRK(a, b)
    real(RK), intent(inout) :: a, b
    real(RK) :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapRealRK

  elemental subroutine swapIntIK(a, b)
    integer(IK), intent(inout) :: a, b
    integer(IK) :: tmp
    tmp = a
    a = b
    b = tmp
  end subroutine swapIntIK

end module NumericKinds