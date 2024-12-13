module DimensionsWrapper
    implicit none
    private
    public :: DimensionsWrapper_t

    type, abstract :: DimensionsWrapper_t
    contains
        procedure(DimensionsWrapper_Set), deferred, pass :: Set
        procedure(DimensionsWrapper_Get), deferred, pass :: Get
    end type DimensionsWrapper_t

    abstract interface
        subroutine DimensionsWrapper_Set(this, value)
            import :: DimensionsWrapper_t
            class(DimensionsWrapper_t), intent(inout) :: this
            integer, intent(in) :: value
        end subroutine DimensionsWrapper_Set

        subroutine DimensionsWrapper_Get(this, value)
            import :: DimensionsWrapper_t
            class(DimensionsWrapper_t), intent(in) :: this
            integer, intent(out) :: value
        end subroutine DimensionsWrapper_Get
    end interface

end module DimensionsWrapper

module ConcreteDimensionsWrapper5D
    use DimensionsWrapper
    implicit none

    type, extends(DimensionsWrapper_t) :: ConcreteWrapper
        integer :: storedValue = 0
    contains
        procedure :: Set => Concrete_Set
        procedure :: Get => Concrete_Get
    end type ConcreteWrapper

contains

    subroutine Concrete_Set(this, value)
        class(ConcreteWrapper), intent(inout) :: this
        integer, intent(in) :: value
        this%storedValue = value
    end subroutine Concrete_Set

    subroutine Concrete_Get(this, value)
        class(ConcreteWrapper), intent(in) :: this
        integer, intent(out) :: value
        value = this%storedValue
    end subroutine Concrete_Get

end module ConcreteDimensionsWrapper5D