program prog
    implicit none
    integer :: nums1(2), nums2(2)
    integer :: i

    nums1(1) = 11
    nums1(2) = 17
    nums2(1) = 19
    nums2(2) = 23

    do i=1,2
        write(*, '(2I3)') nums1(i) + nums2(i)
    end do
end program prog