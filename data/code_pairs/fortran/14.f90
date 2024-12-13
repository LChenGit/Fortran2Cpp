module mod_spectral_shapes
    implicit none
    contains

    ! Function to calculate the peak frequency of the JONSWAP spectrum
    function jonswapPeakFrequency(wspd, fetch, grav) result(peakFrequency)
        real, intent(in) :: wspd, fetch, grav
        real :: peakFrequency
        
        ! Simplified calculation for demonstration
        peakFrequency = wspd * sqrt(fetch / grav)
    end function jonswapPeakFrequency
end module mod_spectral_shapes

program test_jonswap
    use mod_spectral_shapes
    implicit none
    real :: wspd, fetch, grav
    real :: calculated_peak_frequency

    grav = 9.81
    wspd = 10.0  ! Example wind speed (m/s)
    fetch = 1e4  ! Example fetch (m)
    
    calculated_peak_frequency = jonswapPeakFrequency(wspd, fetch, grav)
    print *, "Calculated Peak Frequency: ", calculated_peak_frequency
end program test_jonswap