module typesizes
  integer, parameter :: FourByteReal = selected_real_kind(p=6)
  integer, parameter :: EightByteReal = selected_real_kind(p=15)
end module typesizes

module iminloc_functions
  use typesizes, only: FourByteReal, EightByteReal
  implicit none
contains
  function iminloc_int(array) result(idx)
    integer, dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_int

  function iminloc_float(array) result(idx)
    real(FourByteReal), dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_float

  function iminloc_double(array) result(idx)
    real(EightByteReal), dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_double
end module iminloc_functions