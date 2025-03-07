SUBROUTINE WTPROJ(DLAT, DLON, UVAL, VVAL, CSLT)
  DOUBLE PRECISION DLAT, DLON, UVAL, VVAL, CSLT
  DOUBLE PRECISION TVAL
  TVAL = ACOS(COS(DLAT) * COS(0.5D0 * DLON))
  IF (ABS(TVAL) > 1.D-6) THEN
    TVAL = SIN(TVAL) / TVAL
  ELSE
    TVAL = 1.D0
  END IF
  UVAL = 2.D0 * COS(DLAT) * SIN(0.5D0 * DLON) / TVAL
  VVAL = SIN(DLAT) / TVAL
  UVAL = 0.5D0 * (DLON * CSLT + UVAL)
  VVAL = 0.5D0 * (DLAT + VVAL)
  RETURN
END SUBROUTINE WTPROJ