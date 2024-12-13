! vla_primitives.f90
program vla_primitives
  implicit none
  integer, allocatable :: intvla(:, :, :)
  real, allocatable    :: realvla(:, :, :)
  complex, allocatable :: complexvla(:, :, :)
  logical, allocatable :: logicalvla(:, :, :)
  character(len=1), allocatable :: charactervla(:, :, :)
  
  ! Allocate arrays
  allocate(intvla(11,22,33))
  allocate(realvla(11,22,33))
  allocate(complexvla(11,22,33))
  allocate(logicalvla(11,22,33))
  allocate(charactervla(11,22,33))
  
  ! Initialize arrays
  intvla = 1
  realvla = 3.14
  complexvla = cmplx(2.0, -3.0)
  logicalvla = .TRUE.
  charactervla = 'K'
  
  ! Specific assignments
  intvla(5,5,5) = 42
  realvla(5,5,5) = 4.13
  complexvla(5,5,5) = cmplx(-3.0, 2.0)
  logicalvla(5,5,5) = .FALSE.
  charactervla(5,5,5) = 'X'
end program vla_primitives