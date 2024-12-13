module test_module
    implicit none
    type :: MyType
        integer, allocatable :: data(:)
        integer :: currentSize
    contains
        procedure :: resetArray
    end type MyType

contains

    subroutine resetArray(this)
        class(MyType), intent(inout) :: this
        if (allocated(this%data)) deallocate(this%data)
        this%currentSize = 0
    end subroutine resetArray

end module test_module