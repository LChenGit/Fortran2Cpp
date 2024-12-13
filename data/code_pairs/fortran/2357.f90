MODULE DataPrecisionGlobals

  IMPLICIT NONE

  INTEGER, PARAMETER :: i32=SELECTED_INT_KIND(6)
  INTEGER, PARAMETER :: i64=SELECTED_INT_KIND(12)
  INTEGER, PARAMETER :: r32=KIND(1.0)
  INTEGER, PARAMETER :: r64=KIND(1.0D0)
  INTEGER, PARAMETER :: default_prec=r64
  REAL(r64), PARAMETER :: constant_zero=0.0d0
  REAL(r64), PARAMETER :: constant_one=1.0d0
  REAL(r64), PARAMETER :: constant_minusone=-1.0d0
  REAL(r64), PARAMETER :: constant_twenty=20.0d0
  REAL(r64), PARAMETER :: constant_pointfive=0.5d0
  REAL(r64), PARAMETER :: EXP_LowerLimit=-20.d0
  REAL(r64), PARAMETER :: EXP_UpperLimit= 40.d0

END MODULE DataPrecisionGlobals