program pr42866
  integer, allocatable :: a(:)
  allocate (a(16))
  a = 0
  !$omp parallel
    !$omp sections reduction(+:a)
      !$omp section
      a = a + 1
      !$omp section
      a = a + 2
    !$omp end sections
  !$omp end parallel
  if (any (a /= 3)) stop 1
  deallocate (a)
end program pr42866