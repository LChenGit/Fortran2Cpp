module Coll_gammaN_exclPi_mod
  implicit none

contains

  subroutine DoColl_gammaN_exclPi(eNev, ExclPiCharge, FlagOK, OutPart, XS_Tot)
    implicit none
    type(electronNucleon_event), intent(in) :: eNev
    integer, intent(in) :: ExclPiCharge
    logical, intent(out) :: FlagOK
    real, intent(out) :: XS_Tot
    type(particle), dimension(:), intent(out) :: OutPart
    integer :: NucCharge

    OutPart%ID = 0
    XS_Tot = 0.0
    FlagOK = .false.

    NucCharge = eNev%nucleon%charge - ExclPiCharge
    if (NucCharge < 0 .or. NucCharge > 1) then
      return
    else
      FlagOK = .true.
    endif
  end subroutine DoColl_gammaN_exclPi

  ! Define the types used in the subroutine here for completeness
  type particle
    integer :: ID
  end type particle

  type nucleonType
    integer :: charge
  end type nucleonType

  type electronNucleon_event
    type(nucleonType) :: nucleon
  end type electronNucleon_event

end module Coll_gammaN_exclPi_mod

! Test program
program testColl_gammaN_exclPi
  use Coll_gammaN_exclPi_mod
  implicit none

  type(electronNucleon_event) :: eNev
  integer :: ExclPiCharge
  type(particle), allocatable :: OutPart(:)
  real :: XS_Tot
  logical :: FlagOK
  integer :: i

  ! Initialize test conditions
  eNev%nucleon%charge = 1
  ExclPiCharge = 0
  allocate(OutPart(3))
  call DoColl_gammaN_exclPi(eNev, ExclPiCharge, FlagOK, OutPart, XS_Tot)

  ! Test assertions
  print *, "FlagOK: ", FlagOK
  print *, "XS_Tot: ", XS_Tot
  do i = 1, size(OutPart)
    print *, "OutPart(", i, ")%ID: ", OutPart(i)%ID
  end do
end program testColl_gammaN_exclPi