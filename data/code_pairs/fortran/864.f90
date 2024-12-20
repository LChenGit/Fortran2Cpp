MODULE superd_I
  INTERFACE
    SUBROUTINE superd(C, EIGS, NORBS, NELECS, NUMAT, NAT)
      USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_DOUBLE
      INTEGER, INTENT(IN) :: NORBS, NELECS, NUMAT
      REAL(KIND=C_DOUBLE), DIMENSION(NORBS,NORBS), INTENT(IN) :: C
      REAL(KIND=C_DOUBLE), DIMENSION(NORBS), INTENT(IN) :: EIGS
      INTEGER, DIMENSION(NUMAT), INTENT(IN) :: NAT
    END SUBROUTINE superd
  END INTERFACE
END MODULE superd_I

SUBROUTINE superd(C, EIGS, NORBS, NELECS, NUMAT, NAT)
  USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_DOUBLE
  INTEGER, INTENT(IN) :: NORBS, NELECS, NUMAT
  REAL(KIND=C_DOUBLE), DIMENSION(NORBS,NORBS), INTENT(IN) :: C
  REAL(KIND=C_DOUBLE), DIMENSION(NORBS), INTENT(IN) :: EIGS
  INTEGER, DIMENSION(NUMAT), INTENT(IN) :: NAT
  
  PRINT *, "superd subroutine called."
END SUBROUTINE superd