MODULE mo_column
  CONTAINS
    FUNCTION compute_column(nz, q, t, nproma) RESULT(r)
      INTEGER, INTENT(IN) :: nproma
      INTEGER, INTENT(IN) :: nz
      REAL, INTENT(INOUT) :: t(nz, nproma)
      REAL, INTENT(INOUT) :: q(nz, nproma)
      INTEGER :: k
      REAL :: c
      INTEGER :: r
      INTEGER :: proma

      DO proma = 1, nproma
        c = 5.345
        DO k = 2, nz
          t(k, proma) = c * k
          q(k, proma) = q(k - 1, proma) + t(k, proma) * c
        END DO
        q(nz, proma) = q(nz, proma) * c
      END DO
      r = 0  ! Assuming a meaningful return could be added here
    END FUNCTION compute_column

    SUBROUTINE compute(nz, q, nproma)
      INTEGER, INTENT(IN) :: nproma
      INTEGER, INTENT(IN) :: nz
      REAL :: t(nz, nproma)
      REAL :: q(nz, nproma)
      INTEGER :: result

      result = compute_column(nz, q, t, nproma)
      ! Further processing could be done here if needed
    END SUBROUTINE compute
END MODULE mo_column