program test_program
  implicit none
  integer :: u(1024), v(1024), w(1024)
  integer :: a, b, c, d, e
  integer :: a1, b1, a2, b2, d1, d2
  integer :: i

  ! Initialize arrays
  do i = 1, 1024
    v(i) = i
    w(i) = 1025 - i
  end do

  a = 1
  b = 1024
  d = 75
  ! Parallel operation 1
  !$omp target teams distribute parallel do simd default(none) &
  !$omp& firstprivate(a, b) shared(u, v, w)
  do d = a, b
    u(d) = v(d) + w(d)
  end do

  c = 17
  d = 75
  ! Parallel operation 2
  !$omp target teams distribute parallel do simd default(none) &
  !$omp& firstprivate(a, b, c) shared(u, v, w) &
  !$omp& linear(d) lastprivate(e)
  do d = a, b
    u(d) = v(d) + w(d)
    e = c + d * 5
  end do

  a1 = 0
  b1 = 31
  a2 = 0
  b2 = 31
  d1 = 7
  d2 = 9
  ! Parallel operation 3
  !$omp target teams distribute parallel do simd default(none) &
  !$omp& firstprivate(a1, b1, a2, b2) &
  !$omp& shared(u, v, w) lastprivate(d1, d2) collapse(2)
  do d1 = a1, b1
    do d2 = a2, b2
      u(d1 * 32 + d2 + 1) = v(d1 * 32 + d2 + 1) + w(d1 * 32 + d2 + 1)
    end do
  end do

  ! Test results
  do i = 1, 1024
    if (u(i) /= 1025) then
      print *, "Test failed at index: ", i
      stop
    end if
  end do
  print *, "All tests passed."

end program test_program