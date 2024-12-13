module sa0054_stuff
contains
  ELEMENTAL FUNCTION S_REAL_SUM_I (A)
    REAL :: S_REAL_SUM_I
    REAL, INTENT(IN) :: A
    S_REAL_SUM_I = 2.0 * A
  END FUNCTION S_REAL_SUM_I

  ELEMENTAL FUNCTION S_REAL_SUM_2 (A)
    REAL :: S_REAL_SUM_2
    INTEGER, INTENT(IN) :: A
    S_REAL_SUM_2 = 2.0 * A
  END FUNCTION S_REAL_SUM_2

  SUBROUTINE SA0054 (RDA)
    REAL :: RDA(:)
    RDA = S_REAL_SUM_I (RDA)
    RDA = RDA + S_REAL_SUM_2 (INT (RDA))
  END SUBROUTINE SA0054
end module sa0054_stuff

program test_sa0054
  use sa0054_stuff
  implicit none
  REAL :: RDA(10)
  INTEGER :: i

  ! Initialize RDA array
  RDA = [(REAL(I), I = 1, 10)]

  ! Call SA0054 subroutine
  call SA0054 (RDA)

  ! Test if the subroutine works as expected
  IF (ANY (INT (RDA) .ne. [(6 * I, I = 1, 10)])) THEN
    print *, "Test failed."
    print *, "RDA =", RDA
  ELSE
    print *, "Test passed!"
  END IF
end program test_sa0054