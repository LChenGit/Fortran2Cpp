MODULE A
   IMPLICIT NONE

   TYPE T
      INTEGER, ALLOCATABLE :: v(:)
   END TYPE T

   INTEGER :: n = 0

CONTAINS

   SUBROUTINE FOO
      IMPLICIT NONE
      TYPE(T) :: var
      INTEGER :: suma, i

      ALLOCATE(var%v(n))
      DO i = 1, n
         var%v(i) = i
      END DO

      suma = SUM(var%v(:))
      PRINT *, "Sum:", suma
   END SUBROUTINE FOO

END MODULE A

PROGRAM test
    USE A
    IMPLICIT NONE

    n = 5
    CALL FOO
END PROGRAM test