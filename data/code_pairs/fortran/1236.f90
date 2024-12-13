module neutrino_def
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    ! Constants for core neutrino channels
    integer, parameter :: icore_nu_brem = 1, icore_nu_mUrca = 2, icore_nu_dUrca = 3, icore_nu_PBF = 4
    integer, parameter :: num_core_nu_channels = 4

    ! Constants for crust neutrino channels
    integer, parameter :: icrust_nu_pair = 1, icrust_nu_photo = 2, icrust_nu_plasma = 3, icrust_nu_brems = 4, icrust_nu_pbf = 5
    integer, parameter :: num_crust_nu_channels = 5

    ! Cooling channels
    logical, dimension(num_core_nu_channels), parameter :: core_nu_minimal_cooling = [ .TRUE., .TRUE., .FALSE., .TRUE. ]
    logical, dimension(num_core_nu_channels), parameter :: core_nu_enhanced_cooling = [ .TRUE., .TRUE., .TRUE., .TRUE. ]
    logical, dimension(num_crust_nu_channels), parameter :: crust_nu_full_cooling = [ .TRUE., .TRUE., .TRUE., .TRUE., .TRUE. ]

    type core_neutrino_emissivity_channels
        real(real64) :: total, brem, brem_np, brem_pp, brem_nn, mUrca, mUrca_p, mUrca_n, dUrca, PBF, PBF_n, PBF_p
    end type

    type crust_neutrino_emissivity_channels
        real(real64) :: total, pair, photo, plasma, brems, pbf
    end type

end module neutrino_def