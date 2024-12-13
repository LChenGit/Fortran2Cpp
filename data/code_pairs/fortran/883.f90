module gsw_mod_toolbox
    implicit none
    contains

    ! Mock-up function - replace with the actual function
    real function gsw_gibbs_ice(n0, n1, t, p)
        integer, intent(in) :: n0, n1
        real, intent(in) :: t, p
        gsw_gibbs_ice = t * p * 0.0001
    end function gsw_gibbs_ice
end module gsw_mod_toolbox

module gsw_specvol_ice_module
    use gsw_mod_toolbox
    implicit none
    contains

    real function gsw_specvol_ice(t, p)
        real, intent(in) :: t, p
        gsw_specvol_ice = gsw_gibbs_ice(0, 1, t, p)
    end function gsw_specvol_ice
end module gsw_specvol_ice_module