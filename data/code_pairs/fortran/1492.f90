module aot_extdouble_top_module
  implicit none
  private
  public :: xdble_k
  integer, parameter :: xdble_k = selected_real_kind(18)
end module aot_extdouble_top_module