program DRB104_nowait_barrier_orig_no
    use omp_lib
    implicit none

    integer i, error, len, b
    integer, dimension(:), allocatable :: a

    len = 1000
    b = 5
    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp parallel shared(b, error)
        !$omp do
        do i = 1, len
            a(i) = b+a(i)*5
        end do
        !$omp end do nowait
    !$omp end parallel

    !$omp barrier
    !$omp single
    error = a(9)+1
    !$omp end single

    print 100, error
    100 format ('error =',3i8)

    deallocate(a)
end program
