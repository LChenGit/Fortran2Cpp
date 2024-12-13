MODULE cell_base
  REAL, PARAMETER :: at(3,3) = RESHAPE([1.0d0, 0.0d0, 0.0d0, &
                                        0.0d0, 1.0d0, 0.0d0, &
                                        0.0d0, 0.0d0, 1.0d0], &
                                        SHAPE=[3,3])
END MODULE cell_base

MODULE ldaU_hp
  USE cell_base, ONLY: at
  INTEGER, PARAMETER :: nqsh = 27, nq1 = 3, nq2 = 3, nq3 = 3
  REAL, ALLOCATABLE :: Rvect(:,:)
END MODULE ldaU_hp

SUBROUTINE hp_R_points
  USE ldaU_hp, ONLY: nqsh, Rvect, nq1, nq2, nq3, at
  INTEGER :: i, j, k, icell
  ALLOCATE (Rvect(3,nqsh))
  IF ( nqsh == 1 ) THEN
    Rvect(:,1) = 0.0d0
  ELSE
    icell = 0
    DO i = 1, nq1
      DO j = 1, nq2
        DO k = 1, nq3
           icell = icell + 1
           Rvect(:,icell) = DBLE(i-1) * at(:,1) + &
                            DBLE(j-1) * at(:,2) + &
                            DBLE(k-1) * at(:,3)
        ENDDO
      ENDDO
    ENDDO
  ENDIF
END SUBROUTINE hp_R_points