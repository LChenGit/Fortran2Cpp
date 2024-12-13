program calc_electron_temperature
  implicit none

  integer, parameter :: nLons = 2, nLats = 2, nAlts = 2
  real :: eTemperature(nLons, nLats, nAlts), Temperature(nLons, nLats, nAlts), TempUnit(nLons, nLats, nAlts)
  real :: Altitude_GB(nLons, nLats, nAlts)
  integer :: iBlock, iLon, iLat, iAlt

  ! Initialize arrays with some values for demonstration
  Altitude_GB = reshape([1000.0, 1500.0, 2000.0, 2500.0, &
                         3000.0, 3500.0, 4000.0, 8000.0], shape(Altitude_GB), order=[1,2,3])
  Temperature = 20.0
  TempUnit = 1.0

  ! Arbitrary block number for demonstration
  iBlock = 1

  ! The core subroutine for calc_electron_temperature
  call calc_electron_temperature(eTemperature, Temperature, TempUnit, Altitude_GB, nLons, nLats, nAlts, iBlock)

  ! Print the eTemperature array for demonstration
  do iLon = 1, nLons
     do iLat = 1, nLats
        do iAlt = 1, nAlts
           print *, "eTemperature(", iLon, ",", iLat, ",", iAlt, ") = ", eTemperature(iLon, iLat, iAlt)
        end do
     end do
  end do

contains

  subroutine calc_electron_temperature(eTemp, Temp, TUnit, Alt_GB, Lons, Lats, Alts, Block)
    real, intent(inout) :: eTemp(Lons, Lats, Alts)
    real, intent(in) :: Temp(Lons, Lats, Alts), TUnit(Lons, Lats, Alts), Alt_GB(Lons, Lats, Alts)
    integer, intent(in) :: Lons, Lats, Alts, Block
    integer :: iLon, iLat, iAlt
    real :: Alt

    do iLon = 1, Lons
       do iLat = 1, Lats
          do iAlt = 1, Alts
             Alt = Alt_GB(iLon, iLat, iAlt) / 1000.0
             if (Alt < 130.0) then
                eTemp(iLon, iLat, iAlt) = Temp(iLon, iLat, iAlt) * TUnit(iLon, iLat, iAlt)
             else
                eTemp(iLon, iLat, iAlt) = 0.0
             end if
          end do
       end do
    end do
  end subroutine calc_electron_temperature

end program calc_electron_temperature