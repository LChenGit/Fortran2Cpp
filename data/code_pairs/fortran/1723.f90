! USRMAT.f90
SUBROUTINE USRMAT (I, J, AIJ, INDCAT, PRGOPT, DATTRV, IFLAG)
  INTEGER, INTENT(INOUT) :: I, J, INDCAT
  DOUBLE PRECISION, INTENT(INOUT) :: AIJ
  DOUBLE PRECISION, DIMENSION(*), INTENT(IN) :: PRGOPT, DATTRV
  INTEGER, DIMENSION(10), INTENT(INOUT) :: IFLAG
  INTEGER :: L

  IF (IFLAG(1) .EQ. 1) THEN
       IF (DATTRV(1) .EQ. 0.0) THEN
           I = 0
           J = 0
           IFLAG(1) = 3
       ELSE
           IFLAG(2) = -INT(DATTRV(1))
           IFLAG(3) = INT(DATTRV(2))
           IFLAG(4) = 3
       END IF
       RETURN
  ELSE
       J = IFLAG(2)
       I = IFLAG(3)
       L = IFLAG(4)
       IF (I .EQ. 0) THEN
            IFLAG(1) = 3
            RETURN
       ELSE IF (I .LT. 0) THEN
            J = -I
            I = INT(DATTRV(L))
            L = L + 1
       END IF
       AIJ = DATTRV(L)
       IFLAG(2) = J
       IFLAG(3) = INT(DATTRV(L+1))
       IFLAG(4) = L + 2
       INDCAT = 0
       RETURN
  END IF
END SUBROUTINE USRMAT