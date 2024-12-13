module current_kind
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none

  real(real64), parameter :: Zero = 0.0_real64, One = 1.0_real64, &
                            Quarter = 0.25_real64, Four = 4.0_real64, &
                            Half = 0.5_real64, Eighth = 0.125_real64, &
                            Two = 2.0_real64, Third = 1.0_real64 / 3.0_real64
end module current_kind