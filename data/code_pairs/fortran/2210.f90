real function chgtemp(stationelev, cellelev)
    implicit none
    real :: stationelev, cellelev

    chgtemp = 0.0065 * (stationelev - cellelev)
end function chgtemp