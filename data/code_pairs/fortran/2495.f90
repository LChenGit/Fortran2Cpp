module e_50_3_mod
contains
  subroutine init (v1, v2, N)
    integer :: i, N
    real :: v1(N), v2(N)
    do i = 1, N
      v1(i) = i + 2.0
      v2(i) = i - 3.0
    end do
  end subroutine

  subroutine check (p, N)
    integer :: i, N
    real, parameter :: EPS = 0.00001
    real :: diff, p(N)
    do i = 1, N
      diff = p(i) - (i + 2.0) * (i - 3.0)
      if (diff > EPS .or. -diff > EPS) stop 1
    end do
  end subroutine

  subroutine vec_mult (N)
    integer :: i, N
    real :: p(N), v1(N), v2(N)
    call init (v1, v2, N)
    !$omp target map(to: v1,v2) map(from: p)
      !$omp parallel do
      do i = 1, N
        p(i) = v1(i) * v2(i)
      end do
    !$omp end target
    call check (p, N)
  end subroutine
end module

program test_fortran
  use e_50_3_mod, only: vec_mult
  call vec_mult(10)
  print *, "Test case 1 passed."
  call vec_mult(100)
  print *, "Test case 2 passed."
  call vec_mult(1000)
  print *, "Test case 3 passed."
end program