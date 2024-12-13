module original_module
    implicit none
    integer, target :: t1
    integer, pointer :: p1
    integer, target :: i0 = 2
    integer, target, dimension(3) :: vec = (/1, 1, 1/)
    type :: t
        integer, pointer :: dpc
        integer :: i = 0
    end type t
    type(t), save, target :: u
    integer, pointer :: dp
    integer, pointer :: dp2
    integer, pointer :: dp3
contains
    subroutine init
        p1 => t1
        u%dpc => i0
        dp => i0
        dp2 => vec(2)
        dp3 => u%i
    end subroutine init
end module original_module