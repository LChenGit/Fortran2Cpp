MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute(nz, b, q_subarray, t_subarray)
    INTEGER, INTENT(IN) :: nz, b
    REAL, INTENT(INOUT) :: q_subarray(nz), t_subarray(b)
    INTEGER :: i
    ! Increment each element by 1.0
    DO i = 1, nz
      q_subarray(i) = q_subarray(i) + 1.0
    END DO
    DO i = 1, b
      t_subarray(i) = t_subarray(i) + 1.0
    END DO
  END SUBROUTINE compute
END MODULE mo_column