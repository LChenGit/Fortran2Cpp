module Block_Energy
    implicit none
    real, dimension(:), allocatable :: q_ns
    real, dimension(:), allocatable :: q_na
    real, dimension(:), allocatable :: dbt
    real, dimension(:), allocatable :: wind
    real, dimension(:), allocatable :: ea
    real, dimension(:), allocatable :: press
    real, dimension(:), allocatable :: mu
    real :: alphamu, beta, gmma, smooth_param
    real :: lvp, rb, rho
    real, parameter :: evap_coeff=1.5e-9, pf=0.640, pi=3.14159, rfac=304.8
end module Block_Energy