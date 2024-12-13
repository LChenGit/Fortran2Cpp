MODULE class_pointers

  IMPLICIT NONE

  TYPE, ABSTRACT :: Base
    INTEGER :: x
  CONTAINS
    PROCEDURE(getval_template), DEFERRED :: getval
  END TYPE Base

  TYPE, EXTENDS(Base) :: ChildAType
  CONTAINS
    PROCEDURE :: getval => childa_getval
    PROCEDURE :: alias_t => childa_alias_t
    PROCEDURE :: alias_c => childa_alias_c
  END TYPE ChildAType

  TYPE, EXTENDS(Base) :: ChildBType
  CONTAINS
    PROCEDURE :: getval => childb_getval
  END TYPE ChildBType

  ABSTRACT INTERFACE
    FUNCTION getval_template(self) RESULT(val)
      IMPORT :: Base
      CLASS(Base), INTENT(IN) :: self
      INTEGER :: val
    END FUNCTION getval_template
  END INTERFACE

CONTAINS

  FUNCTION childa_getval(self) RESULT(val)
    CLASS(ChildAType), INTENT(IN) :: self
    INTEGER :: val
    val = self%x
  END FUNCTION childa_getval

  FUNCTION childa_alias_t(self) RESULT(p)
    CLASS(ChildAType), TARGET :: self
    TYPE(ChildAType), POINTER :: p
    p => self
  END FUNCTION childa_alias_t

  FUNCTION childa_alias_c(self) RESULT(p)
    CLASS(ChildAType), TARGET :: self
    CLASS(ChildAType), POINTER :: p
    p => self
  END FUNCTION childa_alias_c

  FUNCTION childb_getval(self) RESULT(val)
    CLASS(ChildBType), INTENT(IN) :: self
    INTEGER :: val
    val = self%x * 2
  END FUNCTION childb_getval

END MODULE class_pointers

PROGRAM test_class_pointers
  USE class_pointers
  IMPLICIT NONE

  CLASS(Base), POINTER :: p
  TYPE(ChildAType), POINTER :: a
  TYPE(ChildBType), POINTER :: b
  TYPE(ChildAType), POINTER :: aliasA
  CLASS(Base), POINTER :: aliasB

  ALLOCATE(ChildAType :: a)
  ALLOCATE(ChildBType :: b)
  a%x = 10
  b%x = 10

  p => a
  PRINT *, 'ChildAType getval:', p%getval()

  aliasA => childa_alias_t(a)
  PRINT *, 'ChildAType alias_t:', aliasA%getval()

  aliasA => childa_alias_c(a)
  PRINT *, 'ChildAType alias_c:', aliasA%getval()

  p => b
  PRINT *, 'ChildBType getval:', p%getval()

  DEALLOCATE(a, b)
END PROGRAM test_class_pointers