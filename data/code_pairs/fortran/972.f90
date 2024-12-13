module Data_Type_Cell
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    type, public :: Type_Vector
        real(real64) :: x = 0.0_real64, y = 0.0_real64, z = 0.0_real64
    end type Type_Vector

    type, public :: Type_Primitive
        logical :: flag = .false.
    contains
        procedure :: free => free_primitive
        procedure :: init => init_primitive
    end type Type_Primitive

    type, public :: Type_Conservative
        logical :: flag = .false.
    contains
        procedure :: free => free_conservative
        procedure :: init => init_conservative
    end type Type_Conservative

    type, public :: Type_Cell
        real(real64) :: V = 0.0_real64
        type(Type_Vector) :: cent
        real(real64) :: Dt = 0.0_real64
        type(Type_Primitive) :: P
        type(Type_Conservative) :: U
        type(Type_Conservative), allocatable :: KS(:)
    contains
        procedure :: init => init_cell
        procedure :: free => free_cell
    end type Type_Cell

contains
    subroutine free_primitive(this)
        class(Type_Primitive), intent(inout) :: this
        this%flag = .false.
    end subroutine free_primitive

    subroutine init_primitive(this)
        class(Type_Primitive), intent(inout) :: this
        this%flag = .true.
    end subroutine init_primitive

    subroutine free_conservative(this)
        class(Type_Conservative), intent(inout) :: this
        this%flag = .false.
    end subroutine free_conservative

    subroutine init_conservative(this)
        class(Type_Conservative), intent(inout) :: this
        this%flag = .true.
    end subroutine init_conservative

    subroutine free_cell(cell)
        class(Type_Cell), intent(inout) :: cell
        call cell%P%free
        call cell%U%free
        if (allocated(cell%KS)) then
            deallocate(cell%KS)
        endif
    end subroutine free_cell

    subroutine init_cell(cell, rk_ord)
        class(Type_Cell), intent(inout) :: cell
        integer, intent(in) :: rk_ord
        if (allocated(cell%KS)) deallocate(cell%KS)
        allocate(cell%KS(rk_ord))
    end subroutine init_cell

end module Data_Type_Cell

program test_Data_Type_Cell
    use Data_Type_Cell
    implicit none
    type(Type_Cell) :: cell

    ! Initialize a Type_Cell with dummy values to be able to test freeing functionality
    call cell%init(2)
    call cell%free()

    ! Test that KS is deallocated properly
    if (.not. allocated(cell%KS)) then
        print *, "free_cell test passed."
    else
        print *, "free_cell test failed."
    endif
end program test_Data_Type_Cell