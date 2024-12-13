module m_tenstr_rrsw_aer
  implicit none
  save

  ! Assuming kind_rb is equivalent to 8-byte real
  integer, parameter :: kind_rb = selected_real_kind(15, 307)
  ! Assuming these constants based on your usage
  integer, parameter :: nbndsw = 10, naerec = 5

  real(kind=kind_rb) :: rsrtaua(nbndsw,naerec)
  real(kind=kind_rb) :: rsrpiza(nbndsw,naerec)
  real(kind=kind_rb) :: rsrasya(nbndsw,naerec)
end module m_tenstr_rrsw_aer