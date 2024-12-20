program DRB061_matrixvector1_orig_no
    use omp_lib
    implicit none
    call foo
contains
    subroutine foo()
        integer :: i, j, N
        real :: sum
        real, dimension(:,:), allocatable :: a
        real, dimension(:), allocatable :: v, v_out

        N = 100
        allocate (a(N,N))
        allocate (v(N))
        allocate (v_out(N))

        !$omp parallel do private (i,j,sum)
        do i = 1, N
            do j = 1, N
                sum = sum + a(i,j)*v(j)
            end do
            v_out(i) = sum
        end do
        !$omp end parallel do

    end subroutine foo
end program
