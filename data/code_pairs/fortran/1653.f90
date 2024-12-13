module astronomy_module
  implicit none
contains

  double precision function distance(asep, eccn, Tanom)
    double precision, intent(in) :: asep, eccn, Tanom
    distance = asep * (1.0d0 - eccn * eccn) / (1 + eccn * cos(Tanom))
  end function distance

  double precision function trueanomaly(eccn, Eanom)
    double precision, intent(in) :: eccn, Eanom
    double precision :: temp1, temp2
    temp1 = sqrt((1.0d0 + eccn) / (1.0d0 - eccn))
    temp2 = tan(Eanom / 2.0d0)
    trueanomaly = 2.0d0 * atan(temp1 * temp2)
  end function trueanomaly

  subroutine kepler(Manom, Eanom, eccn)
    double precision, intent(in) :: Manom, eccn
    double precision, intent(inout) :: Eanom
    double precision :: Eold, diff, thres
    integer :: i, itmax
    thres = 1.0d-8
    itmax = 100
    i = 0

    do
      Eold = Eanom
      Eanom = Manom + eccn * sin(Eold)
      diff = abs(Eanom - Eold)
      if (diff <= thres .or. i >= itmax) exit
      i = i + 1
    end do
  end subroutine kepler

  subroutine invkepler(Eanom, Manom, eccn)
    double precision, intent(in) :: Eanom, eccn
    double precision, intent(inout) :: Manom
    double precision :: Mold, diff, thres
    integer :: i, itmax
    thres = 1.0d-6
    itmax = 100
    i = 0

    do
      Mold = Manom
      Manom = Eanom - eccn * sin(Mold)
      diff = abs(Manom - Mold)
      if (diff <= thres .or. i >= itmax) exit
      i = i + 1
    end do
  end subroutine invkepler

end module astronomy_module

program test_astronomy
  use astronomy_module
  implicit none
  print *, "Distance Test:", distance(1.0d0, 0.1d0, 0.5d0)
  print *, "True Anomaly Test:", trueanomaly(0.1d0, 0.5d0)
  ! Note: The values for Eanom in kepler and invkepler tests are initial guesses and may be modified as needed
  print *, "Kepler Test:", kepler(0.5d0, 0.1d0, 0.1d0)
  print *, "Inverse Kepler Test:", invkepler(0.5d0, 0.1d0, 0.1d0)
end program test_astronomy