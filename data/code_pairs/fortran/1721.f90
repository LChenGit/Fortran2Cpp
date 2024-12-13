module mtadj_variables

  integer, parameter :: NDIM = 10, NPT = 20, NMAX_TAPER = 5

  integer :: iker
  integer :: itap
  character(len=150) :: meas_dir
  character(len=150) :: adj_dir

  logical :: BANDPASS
  real :: tshort, tlong
  real :: fstart, fend

  real :: BEFORE_SHIFT
  real :: wtr
  real :: npi
  integer :: ntaper
  real :: wtr_mtm
  real :: MIN_DT_SIGMA, MIN_DlnA_SIGMA

  logical :: SELECT_WINDOW
  integer :: ncycle_in_window
  real :: dt_fac, dt_max_scale, err_fac

  logical :: INCLUDE_ERROR, BANDPASS_ADJ
  real :: b_adj, dt_adj
  integer :: npts_adj

  real, dimension(NDIM) :: data, syn
  real :: b, dt
  integer :: npts

  real, dimension(NPT) :: dataw, synw
  integer :: nstart, nend, nlen

  real :: tshift_cc, dlnA
  real :: sigma_tshift_cc, sigma_dlnA_cc

  real, dimension(NPT,NMAX_TAPER) :: tas

  integer :: i_left, i_right, idf_fd
  real :: f_left, f_right, df_fd
  integer :: i_pmax

  complex, dimension(NPT) :: trans_fdm
  real, dimension(NPT) :: dtau_fdm, dlnA_fdm
  real, dimension(NPT) :: sigma_dtau_fdm, sigma_dlnA_fdm

  integer :: ipwr_t, ipwr_w

end module mtadj_variables