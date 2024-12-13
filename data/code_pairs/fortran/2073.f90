module types
    implicit none

    type :: person
        character(len=20) :: forename
        integer :: age
    end type person

    type :: kids
        type(person) :: oldest_child
        type(person), allocatable, dimension(:) :: other_kids
    end type kids

    type, private :: AUXILIARY
        logical :: diagnostic
        character(len=20) :: message
    end type AUXILIARY

    type :: NUMERIC_SEQ
        integer :: int_val
        real :: real_val
        logical :: log_val
    end type NUMERIC_SEQ

    type :: POINT
        real :: x, y
    contains
        procedure :: length => point_length
    end type POINT

contains
    real function point_length(this)
        class(POINT), intent(in) :: this
        point_length = sqrt(this%x**2 + this%y**2)
    end function point_length
end module types