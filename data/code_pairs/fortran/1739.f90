module precision
  implicit none
  private
  public :: int1, int2, int4, int8
  public :: real4, real8, real16
  public :: ik, rk
  integer, parameter :: int1 = selected_int_kind(1)
  integer, parameter :: int2 = selected_int_kind(2)
  integer, parameter :: int4 = selected_int_kind(8)
  integer, parameter :: int8 = selected_int_kind(16)
  integer, parameter :: real4 = selected_real_kind(6)
  integer, parameter :: real8 = selected_real_kind(15)
  integer, parameter :: real16 = selected_real_kind(32)
  integer, parameter :: ik = int4
  integer, parameter :: rk = real8
end module precision