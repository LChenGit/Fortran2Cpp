! main.f90
module m
    implicit none
    type :: t
        integer, allocatable :: CAF(:)
    end type t
end module m

program main
    use m
    type(t), target :: x, y
    integer, pointer :: ptr(:)
    integer :: i

    allocate(x%CAF(1), y%CAF(1))
    ptr => y%CAF
    ptr(1) = 6

    if (.not.allocated(x%CAF) .or. .not.allocated(y%CAF)) stop "Allocation failed"
    if (y%CAF(1) /= 6) stop "Value assignment failed"

    x%CAF = y%CAF  ! This makes a copy in Fortran, not sharing
    ptr(1) = 123

    if (y%CAF(1) /= 123) stop "Value reassignment failed"
    if (x%CAF(1) == 123) stop "Memory sharing failed"

    print *, "All tests passed."
    deallocate(x%CAF, y%CAF)
end program main