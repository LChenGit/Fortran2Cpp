program test_a2_d0
    real, allocatable :: a2(:,:)
    integer :: nerr
    integer :: me

    !*** Allocate the array
    allocate(a2(2,3), stat = nerr)
    if (nerr /= 0) then
        write(*, '(A)', advance='no') "Allocation failed: Error code: "
        write(*, '(I0)') nerr
        call exit(1)
    end if

    !*** Set the array to zero
    a2 = 0.0

    !*** Obtain the current image number
    me = this_image()

    !*** Print image number and array contents
    print *, "Image ", me, " initialized a2:"
    do i = 1, 2
        do j = 1, 3
            print '(F6.2)', a2(i,j)
        end do
    end do

    !*** Check that me is a valid image number
    if (me < 1) then
        write(*, '(A)') "Invalid image number."
        call exit(1)
    end if

    !*** Success message
    print *, "All tests passed."

end program test_a2_d0