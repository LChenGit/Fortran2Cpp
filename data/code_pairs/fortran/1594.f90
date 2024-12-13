! workshare.f90
subroutine workshare(aa, bb, cc, dd, ee, ff, n)
  implicit none
  integer, intent(in) :: n
  real, dimension(n,n), intent(out) :: aa, cc, ee
  real, dimension(n,n), intent(in) :: bb, dd, ff
  integer :: i, j

  !$omp parallel do
  do i = 1, n
    print *, "omp workshare"
  end do
  !$omp end parallel do

  !$omp critical
  !$omp single
  aa = bb
  !$omp end single
  !$omp end critical

  !$omp parallel
  !$omp single
  cc = dd
  !$omp end single
  !$omp end parallel

  ee = ff

end subroutine workshare

program testWorkshare
  implicit none
  integer, parameter :: n = 4
  real :: aa(n,n), bb(n,n), cc(n,n), dd(n,n), ee(n,n), ff(n,n)
  integer :: i, j

  ! Initialize arrays
  do i = 1, n
     do j = 1, n
        bb(i,j) = i * n + j
        dd(i,j) = i * n + j + n*n
        ff(i,j) = i * n + j + 2*n*n
     end do
  end do

  call workshare(aa, bb, cc, dd, ee, ff, n)

  ! Output results for verification
  print *, 'aa:'
  do i = 1, n
     print *, aa(i,:)
  end do

  print *, 'cc:'
  do i = 1, n
     print *, cc(i,:)
  end do

  print *, 'ee:'
  do i = 1, n
     print *, ee(i,:)
  end do
end program testWorkshare