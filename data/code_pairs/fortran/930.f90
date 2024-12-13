MODULE types
  TYPE :: tp4
    REAL, PRIVATE :: x = 0.0
    INTEGER, PRIVATE :: i = 0
  END TYPE tp4

  TYPE :: tp3
    REAL :: x = 0.0
    INTEGER, PRIVATE :: i = 0
  END TYPE tp3

  TYPE :: tp2
    TYPE(tp3) :: t
  END TYPE tp2

  TYPE :: tp1
    INTEGER :: i = 0
    TYPE(tp2) :: t
  END TYPE tp1
END MODULE types

MODULE nml
  USE types
  IMPLICIT NONE
  TYPE(tp1) :: t1
  TYPE(tp4) :: t4
  PRIVATE :: i = 0

CONTAINS

  SUBROUTINE y()
    TYPE(tp2) :: y2
    TYPE(tp3) :: y3
    PRINT *, "Subroutine y executed."
  END SUBROUTINE y
END MODULE nml

PROGRAM main
  USE nml
  IMPLICIT NONE

  TYPE :: tp5
    TYPE(tp4) :: t
  END TYPE tp5

  TYPE(tp5) :: t5

  PRINT *, "Main program executed."

CONTAINS

  SUBROUTINE z()
    PRINT *, "Subroutine z executed."
  END SUBROUTINE z

END PROGRAM main