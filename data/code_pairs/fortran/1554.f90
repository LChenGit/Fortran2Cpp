module DimensionsWrapper7D
    implicit none

    type, abstract :: DimensionsWrapper7D_t
    contains
        procedure(dimensionsWrapper7D_set), deferred, pass :: Set
        procedure(dimensionsWrapper7D_get), deferred, pass :: Get
        procedure(dimensionsWrapper7D_getPointer), deferred, pass :: GetPointer
    end type DimensionsWrapper7D_t

    abstract interface
        subroutine dimensionsWrapper7D_set(this, Value)
            import :: DimensionsWrapper7D_t
            class(DimensionsWrapper7D_t), intent(inout) :: this
            real, intent(in) :: Value(:,:,:,:,:,:,:)
        end subroutine dimensionsWrapper7D_set

        subroutine dimensionsWrapper7D_get(this, Value)
            import :: DimensionsWrapper7D_t
            class(DimensionsWrapper7D_t), intent(in) :: this
            real, intent(out) :: Value(:,:,:,:,:,:,:)
        end subroutine dimensionsWrapper7D_get

        subroutine dimensionsWrapper7D_getPointer(this, Value)
            import :: DimensionsWrapper7D_t
            class(DimensionsWrapper7D_t), intent(in) :: this
            real, pointer :: Value(:,:,:,:,:,:,:)
        end subroutine dimensionsWrapper7D_getPointer
    end interface

    type, extends(DimensionsWrapper7D_t) :: ConcreteDimensionsWrapper
    contains
        procedure :: Set => ConcreteSet
        procedure :: Get => ConcreteGet
        procedure :: GetPointer => ConcreteGetPointer
    end type ConcreteDimensionsWrapper

contains
    subroutine ConcreteSet(this, Value)
        class(ConcreteDimensionsWrapper), intent(inout) :: this
        real, intent(in) :: Value(:,:,:,:,:,:,:)
        ! Implementation of setting a value (left as an exercise)
    end subroutine ConcreteSet

    subroutine ConcreteGet(this, Value)
        class(ConcreteDimensionsWrapper), intent(in) :: this
        real, intent(out) :: Value(:,:,:,:,:,:,:)
        ! Implementation of getting a value (left as an exercise)
    end subroutine ConcreteGet

    subroutine ConcreteGetPointer(this, Value)
        class(ConcreteDimensionsWrapper), intent(in) :: this
        real, pointer :: Value(:,:,:,:,:,:,:)
        ! Implementation (left as an exercise)
    end subroutine ConcreteGetPointer

end module DimensionsWrapper7D