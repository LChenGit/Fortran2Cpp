program DRB031_truedepfirstdimension_orig_yes
    use omp_lib
    implicit none

    integer :: i, j, n, m
    real, dimension(:,:), allocatable :: b

    n = 1000
    m = 1000
    allocate (b(n,m))

    do i = 1, n
        do j = 1, m
            b(i,j) = 0.5
        end do
    end do

    !$omp parallel do private(j)
    do i = 2, n
        do j = 2, m
            b(i,j) = b(i-1, j-1)
        end do
    end do
    !$omp end parallel do

    print 100, b(500,500)
    100 format ('b(500,500) =',F10.6)

    deallocate(b)
end program
