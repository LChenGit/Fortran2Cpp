MODULE mo_column
  IMPLICIT NONE
CONTAINS

  FUNCTION compute_column(nz, q, t) result(res)
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:)
    REAL, INTENT(INOUT) :: q(:)
    INTEGER :: k
    REAL :: c
    REAL :: res(1:nz)

    c = 5.345
    DO k = 2, nz
      t(k) = c * k
      q(k) = t(k - 1) + t(k) * c
    END DO
    q(nz) = q(nz) * c

    res = t
  END FUNCTION compute_column

  SUBROUTINE compute_all(nz, q, val)
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: val(:)
    REAL, INTENT(INOUT) :: q(:)
    REAL :: res(1:nz)

    val = compute_column(nz, q, val)
  END SUBROUTINE compute_all
END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE
  INTEGER :: nz
  REAL, ALLOCATABLE :: q(:), val(:)

  nz = 5
  ALLOCATE(q(nz), val(nz))
  q = [0.0, 1.0, 2.0, 3.0, 4.0]
  val = [1.0, 2.0, 3.0, 4.0, 5.0]

  CALL compute_all(nz, q, val)

  PRINT *, "Modified q:"
  PRINT *, q
  PRINT *, "Modified val:"
  PRINT *, val

  DEALLOCATE(q, val)
END PROGRAM test_mo_column