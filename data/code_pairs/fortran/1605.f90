module module_global
  implicit none
  save

  character(len=30) :: dirIN = " "
  character(len=30) :: dirOUT = " "
  character(len=30) :: dirTMP = " "
  character(len=30) :: simname = " "
  character(len=30) :: filesim = " "
  character(len=30) :: filexy = " "
  character(len=100) :: filename = " "

  integer :: flagbed = 0
  double precision :: beta = 0.0d0
  double precision :: beta0 = 0.0d0
  double precision :: betaold = 0.0d0
  double precision :: theta = 0.0d0
  double precision :: theta0 = 0.0d0
  double precision :: thetaold = 0.0d0
  double precision :: ds = 0.0d0
  double precision :: ds0 = 0.0d0
  double precision :: dsold = 0.0d0
  double precision :: Rp = 0.0d0
  double precision :: rpic = 0.0d0
  double precision :: rpic0 = 0.0d0
  integer :: jmodel = 0
  double precision :: Cf = 0.0d0
  double precision :: Cf0 = 0.0d0
  double precision :: Cfold = 0.0d0
  double precision :: CD = 0.0d0
  double precision :: CT = 0.0d0
  double precision :: phi = 0.0d0
  double precision :: phiD = 0.0d0
  double precision :: phiT = 0.0d0
  double precision :: F0 = 0.0d0

  double precision :: Ef = 0.0d0
  double precision :: Eb = 0.0d0
  double precision :: Eo = 0.0d0
  double precision :: Ebound = 0.0d0
  double precision :: Lhalfvalley = 0.0d0
  double precision :: Ltransvalley = 0.0d0
  integer :: jbound = 0

  integer :: flagxy0 = 0
  integer :: flag_ox = 0
  integer :: N = 0
  integer :: Nold = 0
  integer :: N0 = 0
  integer :: Nrand = 0
  integer :: jre = 0
  integer :: jnco = 0
  integer :: ksavgol = 0
  double precision :: deltas = 0.0d0
  double precision :: deltas0 = 0.0d0
  double precision :: dsmin = 0.0d0
  double precision :: dsmax = 0.0d0
  double precision :: tollc = 0.0d0
  double precision :: stdv = 0.0d0

  integer :: flag_time = 0
  integer :: flag_dt = 0
  integer :: ivideo = 0
  integer :: ifile = 0
  integer :: nend = 0
  double precision :: TT = 0.0d0
  double precision :: TTs = 0.0d0
  double precision :: kTTfco = 0.0d0
  double precision :: tt0 = 0.0d0
  double precision :: dt0 = 0.0d0
  double precision :: cstab = 0.0d0
end module module_global