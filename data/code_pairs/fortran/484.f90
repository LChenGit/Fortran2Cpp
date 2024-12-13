module zstatn_module
  implicit none
contains
  subroutine zstatn()
    ! Variables
    integer :: nopx, nbx, nrorth, nitref, nrstrt
    double precision :: tcaupd, tcaup2, tcaitr, tceigh, tcgets
    double precision :: tcapps, tcconv, titref, tgetv0, trvec
    double precision :: tmvopx, tmvbx

    nopx   = 0
    nbx    = 0
    nrorth = 0
    nitref = 0
    nrstrt = 0

    tcaupd = 0.0D+0
    tcaup2 = 0.0D+0
    tcaitr = 0.0D+0
    tceigh = 0.0D+0
    tcgets = 0.0D+0
    tcapps = 0.0D+0
    tcconv = 0.0D+0
    titref = 0.0D+0
    tgetv0 = 0.0D+0
    trvec  = 0.0D+0

    tmvopx = 0.0D+0
    tmvbx  = 0.0D+0

    print *, "zstatn subroutine called."
  end subroutine zstatn
end module zstatn_module