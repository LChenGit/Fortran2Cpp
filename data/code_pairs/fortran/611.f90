module foodie_error_codes
  use, intrinsic :: iso_fortran_env, only : int32
  implicit none
  private
  public :: ERROR_UNSUPPORTED_SCHEME
  integer(int32), parameter :: ERROR_UNSUPPORTED_SCHEME = 1 
end module foodie_error_codes