PROGRAM TestIZMAX1
  IMPLICIT NONE
  INTEGER :: RESULT

  ! Test 1: Single-element array
  CALL TEST_SINGLE_ELEMENT()

  ! Test 2: Multi-element array, INCX = 1
  CALL TEST_MULTI_ELEMENT_INCX1()

  ! Test 3: Multi-element array, INCX > 1
  CALL TEST_MULTI_ELEMENT_INCX_GT1()

END PROGRAM TestIZMAX1

SUBROUTINE TEST_SINGLE_ELEMENT()
  COMPLEX*16, ALLOCATABLE :: CX(:)
  INTEGER :: N, INCX, RESULT

  ALLOCATE(CX(1))
  CX(1) = (1.0D0, 2.0D0)
  N = 1
  INCX = 1
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 1 (Single-element array): Expected 1, got", RESULT

  DEALLOCATE(CX)
END SUBROUTINE TEST_SINGLE_ELEMENT

SUBROUTINE TEST_MULTI_ELEMENT_INCX1()
  COMPLEX*16, ALLOCATABLE :: CX(:)
  INTEGER :: N, INCX, RESULT

  ALLOCATE(CX(3))
  CX = [(2.0D0, 2.0D0), (3.0D0, 4.0D0), (1.0D0, 1.0D0)]
  N = 3
  INCX = 1
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 2 (Multi-element, INCX=1): Expected 2, got", RESULT

  DEALLOCATE(CX)
END SUBROUTINE TEST_MULTI_ELEMENT_INCX1

SUBROUTINE TEST_MULTI_ELEMENT_INCX_GT1()
  COMPLEX*16, ALLOCATABLE :: CX(:)
  INTEGER :: N, INCX, RESULT

  ALLOCATE(CX(3))
  CX = [(2.0D0, 2.0D0), (3.0D0, 4.0D0), (1.0D0, 1.0D0)]
  N = 3
  INCX = 2
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 3 (Multi-element, INCX>1): Expected 1, got", RESULT

  DEALLOCATE(CX)
END SUBROUTINE TEST_MULTI_ELEMENT_INCX_GT1

! The IZMAX1 function goes here, as defined in the initial Fortran code you provided.