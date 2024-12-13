module nrtype
  implicit none
  integer, parameter :: i1  = selected_int_kind(2)
  integer, parameter :: i2  = selected_int_kind(4)
  integer, parameter :: i4  = selected_int_kind(9)
  integer, parameter :: i8  = selected_int_kind(18)
  ! C++ does not have a standard 128-bit integer, so we omit i16
  integer, parameter :: sp  = kind(1.0)
  integer, parameter :: dp  = kind(1.0d0)

  real(dp), parameter :: pi    = 3.141592653589793238462643383279502884197_dp
  real(dp), parameter :: pi2   = 1.57079632679489661923132169163975144209858_dp
  real(dp), parameter :: tau   = 6.283185307179586476925286766559005768394_dp
  real(dp), parameter :: sqrt2 = 1.41421356237309504880168872420969807856967_dp
  real(dp), parameter :: euler = 2.71828182845904523536028747135266249775725_dp
end module nrtype

program test_nrtype
  use nrtype
  implicit none

  print *, 'Testing integer kinds...'
  print *, 'Size of i1:', bit_size(1_i1)
  print *, 'Size of i2:', bit_size(1_i2)
  print *, 'Size of i4:', bit_size(1_i4)
  print *, 'Size of i8:', bit_size(1_i8)

  print *, 'Testing constants...'
  print *, 'pi:', pi
  print *, 'pi2:', pi2
  print *, 'tau:', tau
  print *, 'sqrt2:', sqrt2
  print *, 'euler:', euler
end program test_nrtype