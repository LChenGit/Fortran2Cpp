module noseHoover
    implicit none
    integer :: nnos
    real :: kT, gkT, gT
    real, allocatable, dimension(:) :: xi
    real, allocatable, dimension(:) :: v_xi
    real, allocatable, dimension(:) :: Q_i
    real, allocatable, dimension(:) :: G_i
    real, allocatable, dimension(:) :: omega
    logical :: debug
end module noseHoover