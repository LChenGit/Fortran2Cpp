module dStar_crust_def
    implicit none
    integer, parameter :: dp = selected_real_kind(15, 307)
    integer, parameter :: iso_name_length = 10
    integer, parameter :: crust_default_number_table_points = 2048
    real(dp), parameter :: crust_default_lgPmin = 22.0_dp
    real(dp), parameter :: crust_default_lgPmax = 33.5_dp
    real(dp), parameter :: crust_default_temperature = 1.0e8_dp

    type crust_table_type
        logical :: is_loaded = .false.
        integer :: nv = 0
        integer :: nisos = 0
        character(len=iso_name_length), dimension(:), allocatable :: network
        real(dp) :: lgP_min = 0.0_dp, lgP_max = 0.0_dp
        real(dp) :: T = 0.0_dp
        real(dp), dimension(:), allocatable :: lgP
        real(dp), dimension(:,:), pointer :: Y => null()
        real(dp), dimension(:), pointer :: lgRho => null()
        real(dp), dimension(:), pointer :: lgEps => null()
    end type crust_table_type

    type(crust_table_type), save :: crust_table
    logical, save :: crust_is_initialized = .FALSE.
    character(len=256), save :: crust_datadir
end module dStar_crust_def