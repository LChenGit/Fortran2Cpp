SUBROUTINE DLAQGB(M, N, KL, KU, AB, LDAB, R, C, ROWCND, COLCND, AMAX, EQUED)
  INTEGER, INTENT(IN) :: M, N, KL, KU, LDAB
  DOUBLE PRECISION, INTENT(IN) :: AB(LDAB,*), R(*), C(*), ROWCND, COLCND, AMAX
  CHARACTER, INTENT(OUT) :: EQUED
  DOUBLE PRECISION :: SMALL, LARGE, CJ
  INTEGER :: I, J

  EQUED = 'N'
  SMALL = 1.0D-20
  LARGE = 1.0D+20

  IF (M.LE.0 .OR. N.LE.0) THEN
     EQUED = 'N'
     RETURN
  END IF

  IF (ROWCND.GE.0.1 .AND. AMAX.GE.SMALL .AND. AMAX.LE.LARGE) THEN
     IF (COLCND.GE.0.1) THEN
        EQUED = 'N'
     ELSE
        DO J = 1, N
           CJ = C(J)
           DO I = MAX(1, J-KU), MIN(M, J+KL)
              AB(KU+1+I-J, J) = CJ*AB(KU+1+I-J, J)
           END DO
        END DO
        EQUED = 'C'
     END IF
  ELSE
     EQUED = 'B'
  END IF
END SUBROUTINE DLAQGB