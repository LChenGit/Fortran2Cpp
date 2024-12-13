MODULE mo_column
  CONTAINS
  SUBROUTINE compute_column(nz, q, t, nx, ny)
    INTEGER, INTENT(IN) :: ny, nx, nz
    REAL, INTENT(INOUT) :: t(nx, ny, nz)
    REAL, INTENT(INOUT) :: q(nx, ny, nz)
    INTEGER :: k, i, j
    REAL :: c, d

    !$omp target
    !$omp teams
    !$omp distribute collapse(2)
    DO j = 1, ny
      DO i = 1, nx
        c = 5.345
        DO k = 2, nz
          t(i, j, k) = c * k
          d = t(i, j, k) + c
          q(i, j, k) = q(i, j, k - 1) + t(i, j, k) * c + d
        END DO
        q(i, j, nz) = q(i, j, nz) * c
      END DO
    END DO
    !$omp end distribute
    !$omp end teams
    !$omp end target

  END SUBROUTINE compute_column
END MODULE mo_column

PROGRAM test_compute_column
  USE mo_column
  IMPLICIT NONE
  INTEGER :: nx, ny, nz
  REAL, ALLOCATABLE :: q(:, :, :), t(:, :, :)

  nx = 10
  ny = 10
  nz = 10
  ALLOCATE(q(nx, ny, nz))
  ALLOCATE(t(nx, ny, nz))
  
  CALL compute_column(nz, q, t, nx, ny)

  PRINT *, "Sample output q(5,5,5): ", q(5, 5, 5)

END PROGRAM test_compute_column