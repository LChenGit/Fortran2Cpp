module testmodule
  implicit none
  public

  type :: evtlist_type
     real, allocatable, dimension(:) :: p1
     real, allocatable, dimension(:) :: p2
     real, allocatable, dimension(:) :: p3
     real, allocatable, dimension(:) :: p4
  end type evtlist_type

  type :: evtlistlist_type
     type(evtlist_type), allocatable :: evtlist(:)
  end type evtlistlist_type

end module testmodule 

program main
  use testmodule
  implicit none

  type(evtlist_type) :: event
  integer :: i

  ! Allocate arrays within the evtlist_type instance
  allocate(event%p1(10), event%p2(10), event%p3(10), event%p4(10))

  ! Assign values to the arrays
  do i = 1, 10
     event%p1(i) = i * 1.0
     event%p2(i) = i * 2.0
     event%p3(i) = i * 3.0
     event%p4(i) = i * 4.0
  end do

  ! Print the values to verify
  print *, "p1 values: ", event%p1
  print *, "p2 values: ", event%p2
  print *, "p3 values: ", event%p3
  print *, "p4 values: ", event%p4

  ! Deallocate arrays
  deallocate(event%p1, event%p2, event%p3, event%p4)
end program main