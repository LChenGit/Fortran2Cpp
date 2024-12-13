module misc_values
  implicit none
  integer, parameter :: dp = kind(1.0d0)

  type MiscValues
    real(dp) :: mv_leafmol
    real(dp) :: mv_soilw
    real(dp) :: mv_soil2g
    real(dp) :: mv_respref
  end type MiscValues

  type(MiscValues) :: msv

end module misc_values