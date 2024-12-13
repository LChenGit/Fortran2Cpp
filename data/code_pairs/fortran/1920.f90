module CKM
  implicit none
  double precision :: V_ud, V_us, V_ub, V_cd, V_cs, V_cb, V_td, V_ts, V_tb
  double precision :: V_ud2, V_us2, V_ub2, V_cd2, V_cs2, V_cb2, V_td2, V_ts2, V_tb2
  character(len=10) :: InCKM
contains
  subroutine SetCKM(Vud, Vus, Vub, Vcd, Vcs, Vcb, Vtd, Vts, Vtb)
    implicit none
    double precision, intent(in) :: Vud, Vus, Vub, Vcd, Vcs, Vcb, Vtd, Vts, Vtb

    V_ud = Vud
    V_us = Vus
    V_ub = Vub
    V_cd = Vcd
    V_cs = Vcs
    V_cb = Vcb
    V_td = Vtd
    V_ts = Vts
    V_tb = Vtb

    V_ud2 = V_ud * V_ud
    V_us2 = V_us * V_us
    V_ub2 = V_ub * V_ub
    V_cd2 = V_cd * V_cd
    V_cs2 = V_cs * V_cs
    V_cb2 = V_cb * V_cb
    V_td2 = V_td * V_td
    V_ts2 = V_ts * V_ts
    V_tb2 = V_tb * V_tb

    InCKM = "done"
  end subroutine SetCKM
end module CKM