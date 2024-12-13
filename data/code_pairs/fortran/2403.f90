! translation.f90
module types_mod
    implicit none

    type :: t0
        integer :: j = 42
    end type t0

    type :: t
        integer :: i
        class(t0), allocatable :: foo
    end type t
end module types_mod

program translation
    use types_mod
    implicit none

    type(t) :: m

    allocate(t0 :: m%foo)
    m%i = 5

    select type(bar => m%foo)
    type is (t0)
        print *, "Fortran test: bar%j =", bar%j
    end select
end program translation