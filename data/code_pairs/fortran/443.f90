module ecosystems_module
  implicit none
  type :: Deriv
    character(len=10) :: name
  end type Deriv

  character(len=8), dimension(2), parameter :: &
       DEF_ECOSYSTEMS = (/ "Gridxxxx", "StringYY" /)

  type(Deriv), save :: DepEcoSystem = Deriv(DEF_ECOSYSTEMS(1))

contains
  subroutine Init_EcoSystems()
    integer :: i = 2
    DepEcoSystem = Deriv(DEF_ECOSYSTEMS(i))
  end subroutine Init_EcoSystems
end module ecosystems_module

program test_ecosystems
  use ecosystems_module
  implicit none
  
  ! Initial condition check
  if (DepEcoSystem%name /= "Gridxxxx") stop 1
  
  DepEcoSystem%name = 'ABCDEFGHIJ'
  call Init_EcoSystems()
  
  ! After Init_EcoSystems
  if (DepEcoSystem%name /= "StringYY") stop 2
end program test_ecosystems