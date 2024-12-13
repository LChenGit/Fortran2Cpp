module Dimensions_Class
  implicit none
  private

  public :: new_Dimensions

  type, public :: Dimensions
    private
    integer, allocatable :: dimensionList(:)
    integer :: numberOfDimensions = 0
    integer :: indexOfSpecialDimension = 0
  contains
    procedure :: isInitialized
    procedure :: delete
    procedure :: print
    procedure :: getOrderedDimensions
    procedure :: getDimensions
    procedure :: length
  end type Dimensions

contains

  function new_Dimensions(dimList, specialIndex) result(this)
    type(Dimensions) :: this
    integer, intent(in) :: specialIndex
    integer, intent(in) :: dimList(:)

    this%dimensionList = dimList
    this%numberOfDimensions = size(dimList)
    this%indexOfSpecialDimension = specialIndex
  end function new_Dimensions

  logical function isInitialized(this) result(isInit)
    class(Dimensions), intent(in) :: this
    isInit = allocated(this%dimensionList)
  end function isInitialized

  subroutine delete(this)
    class(Dimensions), intent(inout) :: this
    if (allocated(this%dimensionList)) then
      deallocate(this%dimensionList)
      this%numberOfDimensions = 0
      this%indexOfSpecialDimension = 0
    end if
  end subroutine delete

  subroutine print(this)
    class(Dimensions), intent(in) :: this
    print *, "Dimensions:"
    if (allocated(this%dimensionList)) then
      print *, this%dimensionList
    else
      print *, "Dimensions are not initialized."
    end if
  end subroutine print

  function getOrderedDimensions(this) result(orderedDims)
    class(Dimensions), intent(in) :: this
    integer, allocatable :: orderedDims(:)

    orderedDims = this%dimensionList
    call bubbleSort(orderedDims)
  end function getOrderedDimensions

  function getDimensions(this) result(dims)
    class(Dimensions), intent(in) :: this
    integer, allocatable :: dims(:)

    dims = this%dimensionList
  end function getDimensions

  integer function length(this) result(numDims)
    class(Dimensions), intent(in) :: this
    numDims = this%numberOfDimensions
  end function length

  ! Bubble sort algorithm for sorting integer arrays
  subroutine bubbleSort(array)
    integer, intent(inout) :: array(:)
    integer :: i, j, temp

    do i = 1, size(array)-1
      do j = 1, size(array)-i
        if (array(j) > array(j+1)) then
          temp = array(j)
          array(j) = array(j+1)
          array(j+1) = temp
        end if
      end do
    end do
  end subroutine bubbleSort

end module Dimensions_Class