module simulation_functions
    implicit none
contains
    real function egs_secnds(t0)
        real, intent(in) :: t0
        egs_secnds = 0
    end function egs_secnds

    real function egs_tot_time(flag)
        integer, intent(in) :: flag
        egs_tot_time = 0
    end function egs_tot_time
end module simulation_functions