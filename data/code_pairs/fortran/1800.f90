PROGRAM main
  IMPLICIT NONE
  INTEGER :: n

  n = 5

  myblock: BLOCK
    INTEGER :: arr(n)
    BLOCK
      INTEGER :: arr(2*n)
    END BLOCK
  END BLOCK myblock

  BLOCK
    INTEGER, ALLOCATABLE :: alloc_arr(:)
    ALLOCATE (alloc_arr(n))
  END BLOCK

  BLOCK
    CHARACTER(LEN=n) :: str
    str = "123456789"
  END BLOCK
END PROGRAM main