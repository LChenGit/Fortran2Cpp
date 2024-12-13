module memory_management
  implicit none
contains
  subroutine allocate_memory(Nx, nvars, x, u, u_p, rhs_u, du, Mom)
    integer, intent(in) :: Nx, nvars
    real, allocatable, intent(inout) :: x(:), u(:,:), u_p(:,:), rhs_u(:,:), du(:,:), Mom(:)

    allocate(x(0:Nx))
    allocate(u(1:nvars,0:Nx))
    allocate(u_p(1:nvars,0:Nx))
    allocate(rhs_u(1:nvars,0:Nx))
    allocate(du(1:nvars,0:Nx))
    allocate(Mom(0:Nx))
  end subroutine allocate_memory
end module memory_management

program test_allocate_memory
  use memory_management
  implicit none
  integer, parameter :: Nx = 10
  integer, parameter :: nvars = 5
  real, allocatable :: x(:), Mom(:)
  real, allocatable :: u(:,:), u_p(:,:), rhs_u(:,:), du(:,:)

  call allocate_memory(Nx, nvars, x, u, u_p, rhs_u, du, Mom)
  print *, "Fortran test passed."
end program test_allocate_memory