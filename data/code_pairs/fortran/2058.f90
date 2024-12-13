! File: refinement_module.f90
module refinement_module
    implicit none
contains

    subroutine tag4refinement(mx,my,mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
        implicit none

        integer, intent(in) :: mx,my, mbc, meqn, blockno, init_flag
        double precision, intent(in) :: xlower, ylower, dx, dy, tag_threshold
        double precision, intent(in) :: q(1-mbc:mx+mbc,1-mbc:my+mbc,meqn)
        integer, intent(out) :: tag_patch

        integer :: i,j
        double precision :: qval

        tag_patch = 0

        do j = 1-mbc,my+mbc
            do i = 1-mbc,mx+mbc
                qval = q(i,j,1)
                if (abs(qval) > tag_threshold) then
                    tag_patch = 1
                    return
                endif
            enddo
        enddo
    end subroutine tag4refinement

end module refinement_module

! File: testTag4Refinement.f90
program testTag4Refinement
    use refinement_module
    implicit none

    integer, parameter :: mx = 2, my = 2, mbc = 1, meqn = 1
    double precision :: q(-mbc:mx+mbc,-mbc:my+mbc,meqn)
    double precision :: xlower, ylower, dx, dy, tag_threshold
    integer :: blockno, init_flag, tag_patch

    ! Test case 1: No values exceed the threshold
    q = 0.0
    tag_threshold = 1.0
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 1 (no exceed):", tag_patch

    ! Test case 2: At least one value exceeds the threshold
    q = 0.0
    q(0,0,1) = 2.0  ! Exceeds threshold
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 2 (one exceed):", tag_patch

    ! Test case 3: Value exactly on the threshold
    q = 0.0
    q(0,0,1) = 1.0  ! Exactly the threshold
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 3 (on threshold):", tag_patch

end program testTag4Refinement