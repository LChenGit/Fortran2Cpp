subroutine multev(d,p,nv)
      implicit none
      double precision, dimension(*) :: d
      double precision, dimension(nv,nv) :: p
      integer :: i, j, nv

      do i = 1, nv
         do j = 1, nv
            p(j,i) = p(j,i) / d(i)
         end do
      end do
end

program test_multev
      implicit none
      double precision, dimension(3) :: d
      double precision, dimension(3,3) :: p
      integer :: i, j

      ! Initialize the vector d
      d = (/2.0, 3.0, 4.0/)

      ! Initialize the matrix p
      p = reshape((/(i*10.0 + j, i=1,3, j=1,3)/), (/3,3/))

      call multev(d, p, 3)

      ! Print the result
      do i = 1, 3
         do j = 1, 3
            print *, 'p(', i, ',', j, ') = ', p(i,j)
         end do
      end do
end program test_multev