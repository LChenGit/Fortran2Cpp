module polytrope_eos
  implicit none

  type :: poly_eos
     double precision :: K, gamma
     double precision :: rho, e
     double precision :: drho_dp, de_dp
     double precision :: p
  end type poly_eos

  type(poly_eos), save :: eos_data
  
contains

  subroutine eos_init(K, gamma)
    double precision, intent(in) :: K, gamma
    eos_data%K = K
    eos_data%gamma = gamma
  end subroutine eos_init
  
  subroutine eos_p(pres)
    double precision, intent(in) :: pres
    eos_data%p = pres
    eos_data%rho = (eos_data%p/eos_data%K)**(1.0d0/eos_data%gamma)
    call eos_compute()
  end subroutine eos_p

  subroutine eos_rho(dens)
    double precision, intent(in) :: dens
    eos_data%rho = dens
    eos_data%p = eos_data%K * (eos_data%rho**eos_data%gamma)
    call eos_compute()
  end subroutine eos_rho

  subroutine eos_compute()
    eos_data%e = (eos_data%p/eos_data%rho)/(eos_data%gamma - 1.0d0)
    eos_data%drho_dp = (1.0d0/(eos_data%K*eos_data%gamma))* &
         eos_data%rho**(1.0d0-eos_data%gamma)
    eos_data%de_dp = (-eos_data%p/(eos_data%gamma - 1.0d0)/ &
         (eos_data%rho**2))*eos_data%drho_dp + &
         (1.0d0/eos_data%rho/(eos_data%gamma - 1.0d0))
  end subroutine eos_compute
  
end module polytrope_eos