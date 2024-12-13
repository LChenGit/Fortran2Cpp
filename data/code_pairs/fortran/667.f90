MODULE parameters
  IMPLICIT NONE
  INTEGER, PARAMETER :: ntypx  = 10
  INTEGER, PARAMETER :: npsx   = ntypx
  INTEGER, PARAMETER :: npk    = 40000
  INTEGER, PARAMETER :: lmaxx  = 3
  INTEGER, PARAMETER :: nchix  = 6
  INTEGER, PARAMETER :: ndmx   = 2000
  INTEGER, PARAMETER :: nbrx   = 28
  INTEGER, PARAMETER :: lqmax  = 2*lmaxx+1
  INTEGER, PARAMETER :: nqfx   = 8
  INTEGER, PARAMETER :: nacx   = 10
  INTEGER, PARAMETER :: nsx    = ntypx
  INTEGER, PARAMETER :: natx   = 5000
  INTEGER, PARAMETER :: npkx   = npk
  INTEGER, PARAMETER :: ncnsx  = 101
  INTEGER, PARAMETER :: nspinx = 2
  INTEGER, PARAMETER :: nhclm  = 4
  INTEGER, PARAMETER :: max_nconstr = 100
END MODULE parameters