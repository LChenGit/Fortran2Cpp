MODULE TT
  CONTAINS
    ELEMENTAL REAL FUNCTION two(N)
      INTEGER, INTENT(IN) :: N
      two = REAL(N) * 2.0
    END FUNCTION two

    ELEMENTAL REAL FUNCTION twopointfive(N)
      INTEGER, INTENT(IN) :: N
      twopointfive = REAL(N) * 2.5
    END FUNCTION twopointfive
END MODULE TT