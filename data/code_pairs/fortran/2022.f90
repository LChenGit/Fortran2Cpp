module constants
  implicit none
  double precision, parameter :: ZERO = 0.0d0
  double precision, parameter :: PI = 3.14159265358979323846d0
  double precision, parameter :: TWO_PI = 2.0d0 * PI
  double precision, parameter :: TINYVAL = 1.0d-10
end module constants

program test_reduce
  use constants
  implicit none

  double precision :: theta, phi

  ! Test 1
  theta = -0.1d0
  phi = TWO_PI + 0.1d0
  call reduce(theta, phi)
  print *, "Test 1 (Theta, Phi): ", theta, phi

  ! Test 2
  theta = 3*PI/2
  phi = -0.1d0
  call reduce(theta, phi)
  print *, "Test 2 (Theta, Phi): ", theta, phi

contains

  subroutine reduce(theta, phi)
    use constants, only: ZERO, PI, TWO_PI, TINYVAL
    implicit none
    double precision, intent(inout) :: theta, phi
    integer :: i
    double precision :: th, ph

    ! Fix to ensure tiny values adjustment
    if (abs(theta) < TINYVAL) theta = theta + 0.0000001d0
    if (abs(phi) < TINYVAL) phi = phi + 0.0000001d0
    
    th = theta
    ph = phi

    ! Adjust phi to be within [0, TWO_PI]
    if (ph < ZERO .or. ph > TWO_PI) then
      i = int(ph/TWO_PI)
      if (ph < ZERO) then
        ph = ph+(abs(i)+1)*TWO_PI
      else
        ph = ph-abs(i)*TWO_PI
      end if
      phi = ph
    end if
    
    ! Adjust theta to be within [0, PI]
    if (th < ZERO .or. th > PI) then
      i = int(th/PI)
      if (th > ZERO) then
        if (mod(i,2) /= 0) then
          th = (i+1)*PI - th
          ph = ph + PI
        else
          th = th - i*PI
        end if
      else
        th = -th
        ph = ph + PI
      end if
      if (ph >= TWO_PI) ph = ph - TWO_PI
      theta = th
      phi = ph
    end if
  end subroutine reduce

end program test_reduce