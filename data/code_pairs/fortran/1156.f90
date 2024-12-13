module bar
  implicit none
  public :: ESMF_Time, operator(+)

  type, public :: ESMF_Time
     integer :: MM
  end type ESMF_Time

  interface operator(+)
     module procedure add
  end interface

contains

  function add(x, y) result(z)
    type(ESMF_Time), intent(in) :: x, y
    type(ESMF_Time) :: z

    z%MM = x%MM ! Mimicking the behavior observed in the unit test
  end function add

end module bar