PROGRAM ex1_test
  use omp_lib
  IMPLICIT NONE

  integer :: num_steps = 100000
  real(8) :: step
  real(8) :: pi, x
  real(8) :: summ
  integer :: i
  real(8), parameter :: known_pi = 3.14159265358979323846
  real(8) :: error_margin = 0.001
  real(8) :: error

  step = 1.0d0 / num_steps

  summ = 0.0d0
  !$OMP PARALLEL DO REDUCTION(+:summ) PRIVATE(x)
  do i=0, num_steps - 1
    x = (i + 0.5d0) * step
    summ = summ + 4.0d0 / (1.0d0 + x * x)
  end do
  !$OMP END PARALLEL DO

  pi = summ * step
  
  error = abs(known_pi - pi)
  
  IF (error <= error_margin) THEN
    write(*,*) 'Test Passed: pi is ', pi
  ELSE
    write(*,*) 'Test Failed: pi is ', pi, ' with error ', error
  END IF

END PROGRAM ex1_test