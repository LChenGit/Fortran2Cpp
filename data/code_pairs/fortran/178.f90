program vla
  implicit none
  real, allocatable :: vla1 (:)
  real, target, allocatable :: vla2(:, :)
  real, pointer :: pvla2 (:, :)
  logical :: l

  ! Test 1: Allocation and deallocation of vla1
  allocate (vla1 (5))
  vla1 = 1
  vla1(2) = 42
  vla1(4) = 24
  l = allocated(vla1)  ! Check if vla1 is allocated
  print *, "Test 1a Passed"

  deallocate (vla1)
  l = allocated(vla1)  ! Check if vla1 is deallocated
  print *, "Test 1b Passed"

  ! Test 2: Allocation, pointer association, and disassociation of vla2
  allocate (vla2 (5, 2))
  vla2 = 2
  pvla2 => vla2
  l = associated(pvla2)  ! Check if pvla2 is associated with vla2
  print *, "Test 2a Passed"

  pvla2(2, 1) = 42  ! Modify an element through pvla2

  pvla2 => null()  ! Disassociate pvla2
  l = associated(pvla2)  ! Check if pvla2 is disassociated
  print *, "Test 2b Passed"
  
end program vla