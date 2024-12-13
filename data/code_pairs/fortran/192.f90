! Module definition with types
module base_types
    implicit none
    ! Define precision
    integer, parameter :: p = selected_real_kind(15, 307)

    ! Definition of types
    type alloc_int1d
        integer, allocatable :: v(:)
    end type alloc_int1d

    type alloc_rp1d
        real(p), allocatable :: v(:)
    end type alloc_rp1d

    type alloc_int2d
        integer, allocatable :: v(:,:)
    end type alloc_int2d

    type alloc_rp2d
        real(p), allocatable :: v(:,:)
    end type alloc_rp2d
end module base_types

! Main program for testing
program test_base_types
    use base_types
    implicit none

    type(alloc_int1d) :: example_int1d
    type(alloc_rp1d) :: example_rp1d
    type(alloc_int2d) :: example_int2d
    type(alloc_rp2d) :: example_rp2d

    ! Test alloc_int1d
    allocate(example_int1d%v(5))
    example_int1d%v = [1, 2, 3, 4, 5]
    print *, 'alloc_int1d:', example_int1d%v
    deallocate(example_int1d%v)

    ! Test alloc_rp1d
    allocate(example_rp1d%v(5))
    example_rp1d%v = [1.0_p, 2.0_p, 3.0_p, 4.0_p, 5.0_p]
    print *, 'alloc_rp1d:', example_rp1d%v
    deallocate(example_rp1d%v)

    ! Test alloc_int2d
    allocate(example_int2d%v(2,3))
    example_int2d%v = reshape([1, 2, 3, 4, 5, 6], [2,3])
    print *, 'alloc_int2d:'
    print *, example_int2d%v
    deallocate(example_int2d%v)

    ! Test alloc_rp2d
    allocate(example_rp2d%v(2,3))
    example_rp2d%v = reshape([1.0_p, 2.0_p, 3.0_p, 4.0_p, 5.0_p, 6.0_p], [2,3])
    print *, 'alloc_rp2d:'
    print *, example_rp2d%v
    deallocate(example_rp2d%v)
end program test_base_types