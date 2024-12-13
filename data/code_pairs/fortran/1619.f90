MODULE StringParser
  IMPLICIT NONE
  INTEGER, PARAMETER :: MaxStringLength=132
  INTEGER, PARAMETER :: MaxStringTokens=100
  CHARACTER(LEN=MaxStringLength), ALLOCATABLE :: StringParts(:)
END MODULE StringParser