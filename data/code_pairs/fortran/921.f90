! Assuming the kinds are defined in an external module, but for completeness:
MODULE mod_kinds
  INTEGER, PARAMETER :: int_kind = SELECTED_INT_KIND(15)
  INTEGER, PARAMETER :: log_kind = KIND(.TRUE.)
  INTEGER, PARAMETER :: real_kind = SELECTED_REAL_KIND(p=6, r=37)
  INTEGER, PARAMETER :: char_len = 30
END MODULE mod_kinds

MODULE def_nests
  USE mod_kinds
  IMPLICIT NONE

  TYPE :: grid
    INTEGER(int_kind) :: tdm, time_step, tstart_yy, tstart_mm, tstart_dd
    INTEGER(int_kind) :: tend_yy, tend_mm, tend_dd
    LOGICAL(log_kind) :: dataExist, tilted, orthogrid
    REAL(real_kind)   :: fill_value
    CHARACTER(len=char_len) :: fnameold, time_units, uname, vname, wname
    CHARACTER(len=char_len) :: densname, salnname, tempname
  END TYPE grid
END MODULE def_nests