module types_mod
    implicit none

    type, public :: baz_type
        integer :: id = 0
    end type baz_type

    type, public, extends(baz_type) :: meow_type
        integer :: special_id = 1
    end type meow_type

end module types_mod