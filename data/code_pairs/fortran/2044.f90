module SfrDiversionModule
  implicit none
  
  type :: SfrDiversionType
     integer :: id
     real :: flowRate
  end type SfrDiversionType

contains

  subroutine addDiversion(list, id, flowRate)
    type(SfrDiversionType), intent(inout), allocatable :: list(:)
    integer, intent(in) :: id
    real, intent(in) :: flowRate
    type(SfrDiversionType) :: newDiversion
    
    newDiversion%id = id
    newDiversion%flowRate = flowRate
    if (.not. allocated(list)) then
      allocate(list(1))
      list(1) = newDiversion
    else
      call appendToList(list, newDiversion)
    endif
  end subroutine addDiversion

  subroutine appendToList(list, diversion)
    type(SfrDiversionType), intent(inout), allocatable :: list(:)
    type(SfrDiversionType), intent(in) :: diversion
    integer :: newSize
    
    newSize = size(list) + 1
    allocate(list(newSize))
    list(newSize) = diversion
  end subroutine appendToList

  function findDiversionById(list, id) result(foundDiversion)
    type(SfrDiversionType), intent(in), allocatable :: list(:)
    integer, intent(in) :: id
    type(SfrDiversionType), allocatable :: foundDiversion
    integer :: i

    do i = 1, size(list)
      if (list(i)%id == id) then
         allocate(foundDiversion)
         foundDiversion = list(i)
         return
      endif
    end do
    foundDiversion = null()  ! If not found
  end function findDiversionById

end module SfrDiversionModule

program testSfrDiversion
  use SfrDiversionModule
  implicit none

  type(SfrDiversionType), allocatable :: diversionList(:)
  type(SfrDiversionType), allocatable :: foundDiversion
  integer :: i

  ! Test adding diversions
  call addDiversion(diversionList, 1, 100.0)
  call addDiversion(diversionList, 2, 200.0)

  if (allocated(diversionList)) then
    if (size(diversionList) == 2) then
      print *, "Test passed: Correct number of diversions added."
    else
      print *, "Test failed: Incorrect number of diversions added."
    endif
  else
    print *, "Test failed: Diversion list not allocated."
  endif

  ! Test searching for a specific diversion by ID
  foundDiversion = findDiversionById(diversionList, 2)

  if (allocated(foundDiversion)) then
    print *, "Test passed: Diversion with ID 2 found."
  else
    print *, "Test failed: Diversion with ID 2 not found."
  endif

end program testSfrDiversion