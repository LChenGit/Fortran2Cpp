SUBROUTINE DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX)
  INTEGER, INTENT(IN) :: N1, N2, DTRD1, DTRD2
  DOUBLE PRECISION, INTENT(IN) :: A(*)
  INTEGER, INTENT(OUT) :: INDEX(*)
  INTEGER :: I, IND1, IND2, N1SV, N2SV

  N1SV = N1
  N2SV = N2
  IF (DTRD1 > 0) THEN
     IND1 = 1
  ELSE
     IND1 = N1
  END IF
  IF (DTRD2 > 0) THEN
     IND2 = N1 + 1
  ELSE
     IND2 = N1 + N2
  END IF
  I = 1
  
  DO WHILE (N1SV > 0 .AND. N2SV > 0)
     IF (A(IND1) <= A(IND2)) THEN
        INDEX(I) = IND1
        I = I + 1
        IND1 = IND1 + DTRD1
        N1SV = N1SV - 1
     ELSE
        INDEX(I) = IND2
        I = I + 1
        IND2 = IND2 + DTRD2
        N2SV = N2SV - 1
     END IF
  END DO
  
  IF (N1SV == 0) THEN
     DO WHILE (N2SV > 0)
        INDEX(I) = IND2
        I = I + 1
        IND2 = IND2 + DTRD2
        N2SV = N2SV - 1
     END DO
  ELSE
     DO WHILE (N1SV > 0)
        INDEX(I) = IND1
        I = I + 1
        IND1 = IND1 + DTRD1
        N1SV = N1SV - 1
     END DO
  END IF
END SUBROUTINE DLAMRG

PROGRAM testDLAMRG
  IMPLICIT NONE
  INTEGER, PARAMETER :: n1=5, n2=5
  DOUBLE PRECISION, DIMENSION(n1+n2) :: A
  INTEGER, DIMENSION(n1+n2) :: INDEX
  INTEGER :: i

  A = (/1.0, 6.0, 3.0, 7.0, 5.0, 2.0, 8.0, 4.0, 9.0, 10.0/)
  CALL DLAMRG(n1, n2, A, 1, 1, INDEX)

  PRINT *, 'INDEX:'
  DO i = 1, n1+n2
     PRINT *, INDEX(i)
  END DO
END PROGRAM testDLAMRG