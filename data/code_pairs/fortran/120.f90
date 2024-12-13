program test_per_labsim2
      implicit none
      integer :: n, itmax
      double precision, allocatable :: a(:,:), b(:), x(:)
      double precision :: eps
      integer :: i

      n = 2
      itmax = 100
      eps = 1.0e-6
      allocate(a(n,n), b(n), x(n))

      ! Example system: x + y = 3, 2x + y = 4
      a(1,1) = 1.0
      a(1,2) = 1.0
      a(2,1) = 2.0
      a(2,2) = 1.0
      b(1) = 3.0
      b(2) = 4.0

      call per_labsim2(n, a, b, x, eps, itmax)

      print *, "Solution x:"
      do i = 1, n
         print *, x(i)
      end do

      deallocate(a, b, x)

contains

      subroutine per_labsim2(n, a, b, x, eps, itmax)
            implicit none
            integer :: n, itmax, i, j, it, ifl
            double precision, dimension(:, :), intent(inout) :: a
            double precision, dimension(:), intent(inout) :: b, x
            double precision :: eps, xst, ast
            double precision :: sum

            ! Initial setup - scale rows
            do i = 1, n
               ast = a(i, i)
               b(i) = b(i) / ast
               do j = 1, n
                  a(i, j) = a(i, j) / ast
               end do
            end do

            ! Iterative refinement
            do it = 1, itmax
               ifl = 1

               do i = 1, n
                  xst = x(i)
                  sum = 0.0
                  do j = 1, n
                     if (i /= j) sum = sum + a(i, j) * x(j)
                  end do
                  x(i) = b(i) - sum

                  if (abs(xst - x(i)) > eps) ifl = 0
               end do

               if (ifl == 1) exit
            end do

            if (ifl /= 1) then
               print *, 'No convergence after', itmax, 'iterations.'
            endif
      end subroutine per_labsim2

end program test_per_labsim2