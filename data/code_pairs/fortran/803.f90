module data_coarse
  implicit none

  public :: nc, ns_ib, iclev, iclevc

  integer :: nc
  integer :: ns_ib
  integer, dimension(:), allocatable :: iclev
  integer, dimension(:), allocatable :: iclevc
end module data_coarse