MODULE M
  IMPLICIT NONE
CONTAINS

  FUNCTION L() RESULT(res)
    USE, INTRINSIC :: ISO_C_BINDING
    LOGICAL(C_BOOL) :: res
    res = .FALSE.
  END FUNCTION L

  FUNCTION L2() RESULT(res)
    LOGICAL(8) :: res
    res = .FALSE._8
  END FUNCTION L2

  SUBROUTINE S()
    DO WHILE (L())
      ! Loop body would execute if L() returns .TRUE.
    ENDDO
    DO WHILE (L2())
      ! Loop body would execute if L2() returns TRUE (non-zero).
    ENDDO
  END SUBROUTINE S

END MODULE M