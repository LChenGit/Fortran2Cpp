module particles_mod
  implicit none

  type :: particles
    real :: x(2)
  end type particles

contains

  subroutine test_condition(p, test_name)
    type(particles), intent(in) :: p
    character(len=*), intent(in) :: test_name
    logical :: result

    result = all(p%x == [1.0, 1.0])
    if (result) then
      print *, test_name, ": Passed"
    else
      print *, test_name, ": Failed"
    endif
  end subroutine test_condition

end module particles_mod

program main
  use particles_mod
  implicit none

  type(particles) :: p

  ! Test: Initialize and check condition
  p%x = [1.0, 1.0]
  call test_condition(p, "Test 1")

  ! Test: Change condition to fail
  p%x = [0.0, 1.0]
  call test_condition(p, "Test 2")

end program main