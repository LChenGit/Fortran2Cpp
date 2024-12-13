MODULE ppm_module_util_matinv_2x2

  INTERFACE ppm_util_matinv_2x2
    MODULE PROCEDURE ppm_util_matinv_2x2_s
    MODULE PROCEDURE ppm_util_matinv_2x2_d
  END INTERFACE

CONTAINS

  SUBROUTINE ppm_util_matinv_2x2_s(matrix, inverse)
    REAL, INTENT(IN) :: matrix(2,2)
    REAL, INTENT(OUT) :: inverse(2,2)
    REAL :: det
    det = matrix(1,1) * matrix(2,2) - matrix(1,2) * matrix(2,1)
    IF (det == 0.0) THEN
      PRINT *, "Matrix is singular and cannot be inverted."
    ELSE
      inverse(1,1) = matrix(2,2) / det
      inverse(2,2) = matrix(1,1) / det
      inverse(1,2) = -matrix(1,2) / det
      inverse(2,1) = -matrix(2,1) / det
    END IF
  END SUBROUTINE ppm_util_matinv_2x2_s

  SUBROUTINE ppm_util_matinv_2x2_d(matrix, inverse)
    DOUBLE PRECISION, INTENT(IN) :: matrix(2,2)
    DOUBLE PRECISION, INTENT(OUT) :: inverse(2,2)
    DOUBLE PRECISION :: det
    det = matrix(1,1) * matrix(2,2) - matrix(1,2) * matrix(2,1)
    IF (det == 0.0D0) THEN
      PRINT *, "Matrix is singular and cannot be inverted."
    ELSE
      inverse(1,1) = matrix(2,2) / det
      inverse(2,2) = matrix(1,1) / det
      inverse(1,2) = -matrix(1,2) / det
      inverse(2,1) = -matrix(2,1) / det
    END IF
  END SUBROUTINE ppm_util_matinv_2x2_d

END MODULE ppm_module_util_matinv_2x2