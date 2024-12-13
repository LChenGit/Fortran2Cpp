module m_Useful
  implicit none
  private

  integer, parameter, public :: k_pr = kind(1.0d0)
  integer, parameter, public :: k_mw = 40
  integer, parameter, public :: k_ml = 255

  type, private :: frameType
    character(len=k_mw) :: frameLabel
    real(k_pr) :: timestamp
    real(k_pr) :: bondCurrent
  end type frameType

  type, public :: cxzType
    integer :: natoms = 0
    integer :: nframes = 0
    type(frameType), allocatable :: frames(:)
    integer :: atom1, atom2
    real(k_pr) :: x1, y1, z1, x2, y2, z2
    character(len=2) :: element1, element2
  end type cxzType

  public :: error
  public :: GetUnit

contains

  subroutine error(message, routine, critical, uout)
    character(len=*), intent(in) :: message
    character(len=*), intent(in) :: routine
    logical, intent(in) :: critical
    integer, intent(in) :: uout

    if (critical) then
      write(uout,*) "Critical error in subroutine: ", routine
    else
      write(uout,*) "Error message from subroutine: ", routine
    end if
    
    write(uout,*) routine, ": ", message
    
    if (critical) then
      write(uout,*) routine, ": User stop."
      stop
    end if
  end subroutine error

  integer function GetUnit()
    character(len=*), parameter :: myname = 'GetUnit()'
    integer, save :: ustart = 9
    
    ustart = ustart + 1
    GetUnit = ustart
    
  end function GetUnit

end module m_Useful