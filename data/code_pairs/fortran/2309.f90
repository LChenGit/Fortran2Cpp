MODULE multistats
  USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_FLOAT, C_INT
  IMPLICIT NONE

  TYPE, BIND(C) :: SUMMARY
    REAL(C_FLOAT)                             :: VAR_RESIDUL
    REAL(C_FLOAT)                             :: LOGP_SIMULN
    REAL(C_FLOAT)                             :: JUMP_TAKEN
    REAL(C_FLOAT)                             :: QOBS_MEAN
    REAL(C_FLOAT)                             :: QSIM_MEAN
    REAL(C_FLOAT)                             :: QOBS_CVAR
    REAL(C_FLOAT)                             :: QSIM_CVAR
    REAL(C_FLOAT)                             :: QOBS_LAG1
    REAL(C_FLOAT)                             :: QSIM_LAG1
    REAL(C_FLOAT)                             :: RAW_RMSE
    REAL(C_FLOAT)                             :: LOG_RMSE
    REAL(C_FLOAT)                             :: NASH_SUTT
    REAL(C_FLOAT)                             :: NUM_RMSE
    REAL(C_FLOAT)                             :: NUM_FUNCS
    REAL(C_FLOAT)                             :: NUM_JACOBIAN
    REAL(C_FLOAT)                             :: NUMSUB_ACCEPT
    REAL(C_FLOAT)                             :: NUMSUB_REJECT
    REAL(C_FLOAT)                             :: NUMSUB_NOCONV
    INTEGER(C_INT)                            :: MAXNUM_ITERNS
    REAL(C_FLOAT), DIMENSION(20)              :: NUMSUB_PROB
    CHARACTER(LEN=1024)                       :: ERR_MESSAGE
  END TYPE SUMMARY

  TYPE(SUMMARY)                             :: MSTATS
  INTEGER(C_INT)                            :: MOD_IX = 1
  INTEGER(C_INT)                            :: PCOUNT
  INTEGER(C_INT)                            :: FCOUNT

END MODULE multistats

PROGRAM test_multistats
  USE multistats
  IMPLICIT NONE

  MSTATS%VAR_RESIDUL = 1.234_C_FLOAT
  PRINT *, 'VAR_RESIDUL:', MSTATS%VAR_RESIDUL

END PROGRAM test_multistats