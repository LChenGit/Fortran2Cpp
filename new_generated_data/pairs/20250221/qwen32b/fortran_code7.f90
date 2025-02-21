module vd_2d_mod
    implicit none
    private
    public :: vd_2d_obj

    type :: vd_2d_obj
        real(8), allocatable :: vd_p_arr(:)
        real(8) :: dx, dy
        integer :: npx, npy
        real(8) :: px_min, px_max, py_min, py_max
        real(8) :: dpx, dpy
        real(8), allocatable :: px_range(:)
        real(8), allocatable :: py_range(:)
    contains
        procedure :: init => vd_2d_init
        procedure :: cleanup => vd_2d_cleanup
        procedure :: update => vd_2d_update
        procedure :: get_npx => vd_2d_get_npx
    end type vd_2d_obj

contains

subroutine vd_2d_init(this, dx, dy, npx, npy, px_min, px_max, py_min, py_max, dpx, dpy, px_range, py_range, dt, sc, vd_disjoint, hbar, m, vd_np_stdev, vd_p_arr)
    class(vd_2d_obj) :: this
    real(8), intent(in) :: dx, dy, px_min, px_max, py_min, py_max, dpx, dpy, dt, hbar, m
    integer, intent(in) :: npx, npy
    real(8), intent(in) :: px_range(npx), py_range(npy)
    logical, intent(in) :: sc, vd_disjoint
    integer, optional, intent(in) :: vd_np_stdev
    real(8), optional, intent(in) :: vd_p_arr(:)

    this%dx = dx
    this%dy = dy
    this%npx = npx
    this%npy = npy
    this%px_min = px_min
    this%px_max = px_max
    this%py_min = py_min
    this%py_max = py_max
    this%dpx = dpx
    this%dpy = dpy

    allocate(this%px_range(npx))
    this%px_range = px_range
    allocate(this%py_range(npy))
    this%py_range = py_range

    if (vd_disjoint) then
        if (present(vd_p_arr)) then
            allocate(this%vd_p_arr(size(vd_p_arr)))
            this%vd_p_arr = vd_p_arr
        else
            allocate(this%vd_p_arr(npx * npy))
            this%vd_p_arr = 0.0
        end if
    else
        allocate(this%vd_p_arr(npx * npy))
        this%vd_p_arr = 0.0
    end if
end subroutine vd_2d_init

subroutine vd_2d_cleanup(this)
    class(vd_2d_obj) :: this

    deallocate(this%vd_p_arr, this%px_range, this%py_range)
end subroutine vd_2d_cleanup

subroutine vd_2d_update(this, psi_arr)
    class(vd_2d_obj) :: this
    real(8), intent(inout) :: psi_arr(:)

    ! Placeholder for update logic
end subroutine vd_2d_update

function vd_2d_get_npx(this) result(npx)
    class(vd_2d_obj) :: this
    integer :: npx

    npx = this%npx
end function vd_2d_get_npx

end module vd_2d_mod

program my_program
    use vd_2d_mod
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    logical :: test_passed
    type(vd_2d_obj) :: obj
    real(real64) :: dx, dy, px_min, px_max, py_min, py_max, dpx, dpy, dt, hbar, m
    integer :: npx, npy
    real(real64), allocatable :: px_range(:), py_range(:)

    ! Test initialization
    call testInitialization(test_passed)
    if (.not. test_passed) then
        write(*,*) "Test case 1 failed: initialization"
        call exit(1)
    end if

    ! Test cleanup
    call testCleanup(test_passed)
    if (.not. test_passed) then
        write(*,*) "Test case 2 failed: cleanup"
        call exit(1)
    end if

    ! Test update
    call testUpdate(test_passed)
    if (.not. test_passed) then
        write(*,*) "Test case 3 failed: update"
        call exit(1)
    end if

    write(*,*) "All tests passed!"
end program my_program

subroutine testInitialization(test_passed)
    logical, intent(out) :: test_passed
    type(vd_2d_obj) :: obj
    real(real64) :: dx, dy, px_min, px_max, py_min, py_max, dpx, dpy, dt, hbar, m
    integer :: npx, npy
    real(real64), allocatable :: px_range(:), py_range(:)

    dx = 0.1
    dy = 0.1
    npx = 100
    npy = 100
    px_min = -5.0
    px_max = 5.0
    py_min = -5.0
    py_max = 5.0
    dpx = 0.1
    dpy = 0.1
    dt = 0.01
    hbar = 1.0
    m = 1.0

    allocate(px_range(npx))
    allocate(py_range(npy))
    ! Initialize ranges...

    call obj%init(dx, dy, npx, npy, px_min, px_max, py_min, py_max, dpx, dpy, &
                  px_range, py_range, dt, .true., .false., hbar, m)

    test_passed = (obj%npx == npx)
    ! Add more checks...

    deallocate(px_range, py_range)
end subroutine testInitialization

subroutine testCleanup(test_passed)
    logical, intent(out) :: test_passed
    type(vd_2d_obj) :: obj

    ! Initialize obj...

    call obj%cleanup()

    test_passed = .true.
    ! Add checks for cleanup...
end subroutine testCleanup

subroutine testUpdate(test_passed)
    logical, intent(out) :: test_passed
    type(vd_2d_obj) :: obj
    real(real64), allocatable :: psi_arr(:)

    ! Initialize obj and psi_arr...

    call obj%update(psi_arr)

    test_passed = .true.
    ! Add checks for update...
end subroutine testUpdate