program omp_do
  implicit none
  integer :: a(10), b(10)
  integer :: i, j

  a = 10
  j = 0

  !$omp parallel private(i)
    !$omp do linear(j:1)
    do i = 1, 10
      j = j + 1
      b(i) = a(i) * 2
    end do
    !$omp end do
  !$omp end parallel

  print *, j
  print *, b
end program omp_do