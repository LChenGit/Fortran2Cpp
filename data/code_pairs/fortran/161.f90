module mod_alloc
    implicit none
    private
    public :: alloc
    public :: dealloc

contains

    subroutine alloc(x, n)
        real, allocatable, intent(in out) :: x(:)
        integer, intent(in) :: n
        integer :: stat
        character(len=100) :: errmsg

        if (allocated(x)) call dealloc(x)

        allocate(x(n), stat=stat, errmsg=errmsg)
        if (stat > 0) error stop errmsg

    end subroutine alloc

    subroutine dealloc(x)
        real, allocatable, intent(in out) :: x(:)
        integer :: stat
        character(len=100) :: errmsg

        if (allocated(x)) then
            deallocate(x, stat=stat, errmsg=errmsg)
            if (stat > 0) error stop errmsg
        end if
    end subroutine dealloc

end module mod_alloc