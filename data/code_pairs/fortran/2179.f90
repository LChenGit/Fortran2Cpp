! barrel_class.f90
module barrel_class
    implicit none

    type, public :: barrel_t
        private
        integer :: nvats
        real :: vol
        real :: strength
        real, dimension(:,:), allocatable :: vat
    contains
        procedure :: init => barrel_init
        procedure :: del => barrel_del
        procedure :: get_nvats
        procedure :: get_vol
        procedure :: get_strength
        procedure :: distil
    end type barrel_t

contains

    subroutine barrel_init(this, strength)
        class(barrel_t), intent(inout) :: this
        real, intent(in) :: strength
        this%vol = 119.2
        this%strength = strength
    end subroutine barrel_init

    subroutine barrel_del(this)
        class(barrel_t), intent(inout) :: this
        if (allocated(this%vat)) deallocate(this%vat)
    end subroutine barrel_del

    function get_nvats(this) result(n)
        class(barrel_t), intent(in) :: this
        integer :: n
        n = this%nvats
    end function get_nvats

    function get_vol(this) result(v)
        class(barrel_t), intent(in) :: this
        real :: v
        v = this%vol
    end function get_vol

    function get_strength(this) result(s)
        class(barrel_t), intent(in) :: this
        real :: s
        s = this%strength
    end function get_strength

    subroutine distil(this, volume)
        class(barrel_t), intent(inout) :: this
        real, intent(in) :: volume

        if (allocated(this%vat)) deallocate(this%vat)
        this%nvats = ceiling(volume / this%vol)
        allocate(this%vat(this%nvats, 2))  ! Assuming 2 columns for simplicity
    end subroutine distil

end module barrel_class

! test_barrel.f90
program test_barrel
    use barrel_class
    implicit none

    type(barrel_t) :: myBarrel
    real :: test_strength = 50.0
    real :: test_volume = 500.0

    call myBarrel%init(test_strength)
    call myBarrel%distil(test_volume)

    print *, "Number of vats: ", myBarrel%get_nvats()
    print *, "Volume: ", myBarrel%get_vol()
    print *, "Strength: ", myBarrel%get_strength()

    call myBarrel%del()
end program test_barrel