module kind_params
    use, intrinsic :: iso_fortran_env, only: dp => real64
end module kind_params

module schmib_module
    use kind_params, only: dp
    implicit none
contains
    subroutine schmib(u, n, ndim)
        integer, intent(in) :: n, ndim
        real(dp), intent(inout) :: u(ndim,ndim)
        integer :: n1, ii, k, k1, npass, j
        real(dp) :: zero, small, one, dot, scale

        zero = 0.0_dp
        small = 0.01_dp
        one = 1.0_dp
        n1 = n + 1
        ii = 0

        do k = 1, n
            k1 = k - 1
            dot = sum(u(:,n1-k)**2)
            if (abs(dot) < 1.d-20) then
                ii = ii + 1
                if (ii <= ndim) u(ii,n1-k) = one
                cycle
            endif
            scale = one/sqrt(dot)
            u(:,n1-k) = scale*u(:,n1-k)
            if (k1 == 0) cycle
            npass = 0
            do while (npass < 3)
                npass = npass + 1
                do j = 1, k1
                    dot = sum(u(:,n1-j)*u(:,n1-k))
                    u(:,n1-k) = u(:,n1-k) - dot*u(:,n1-j)
                end do
                dot = sum(u(:,n1-k)**2)
                if (abs(dot) < 1.d-20) exit
                if (dot < small .and. npass > 1) exit
                scale = one/sqrt(dot)
                u(:,n1-k) = scale*u(:,n1-k)
                if (dot >= small) exit
            end do
            ii = ii + 1
            if (ii <= ndim) u(ii,n1-k) = one
        end do
    end subroutine schmib
end module schmib_module

program test_schmib
    use kind_params, only: dp
    use schmib_module, only: schmib
    implicit none
    real(dp), allocatable :: u(:,:)
    integer :: n, ndim, i, j

    n = 3
    ndim = 3
    allocate(u(ndim,ndim))

    u = reshape((/ 1.0_dp, 2.0_dp, 3.0_dp, &
                  2.0_dp, 5.0_dp, 6.0_dp, &
                  3.0_dp, 6.0_dp, 14.0_dp /), &
                 shape(u), order=[2,1])

    call schmib(u, n, ndim)

    print *, 'Resulting matrix U after schmib processing:'
    do i = 1, ndim
        print '(3F10.5)', u(i,:)
    end do
end program test_schmib