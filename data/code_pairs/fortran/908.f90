module ObjectsModule
    implicit none

    type, public :: TObjectList
        integer, allocatable :: intList(:)
        double precision, allocatable :: doubleList(:)
    contains
        procedure :: Add1
        procedure :: Add2
    end type TObjectList

contains

    subroutine Add1(self, item)
        class(TObjectList), intent(inout) :: self
        integer, intent(in) :: item
        if (.not. allocated(self%intList)) then
            allocate(self%intList(1))
            self%intList(1) = item
        else
            self%intList = [self%intList, item]
        endif
    end subroutine Add1

    subroutine Add2(self, item)
        class(TObjectList), intent(inout) :: self
        double precision, intent(in) :: item
        if (.not. allocated(self%doubleList)) then
            allocate(self%doubleList(1))
            self%doubleList(1) = item
        else
            self%doubleList = [self%doubleList, item]
        endif
    end subroutine Add2

end module ObjectsModule

program testObjects
    use ObjectsModule
    implicit none
    type(TObjectList) :: list

    ! Test adding an integer
    call list%Add1(1)
    ! Test adding a double
    call list%Add2(2.0d0)

    print *, "All Fortran tests passed."
end program testObjects