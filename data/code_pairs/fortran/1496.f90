program prog
    implicit none
    integer :: i
    integer, dimension(2) :: nums
    integer :: numx
    integer, dimension(4) :: numse

    common /scr/ nums, numx
    equivalence (nums, numse(1)), (numx, numse(3))

    do i = 1, 4
        numse(i) = 10 + i
    end do

    print *, nums(2), nums(1), numse(4), numx
    print *, numse
end program prog