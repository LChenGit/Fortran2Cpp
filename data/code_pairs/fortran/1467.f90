MODULE EGOPS_Utilities
  IMPLICIT NONE
CONTAINS
  FUNCTION dirname(fullfilename) RESULT(dirnameRes)
    CHARACTER(LEN=*), INTENT(IN) :: fullfilename
    CHARACTER(LEN=LEN(fullfilename)) :: dirnameRes
    dirnameRes = ''  ! Placeholder functionality
  END FUNCTION dirname
END MODULE EGOPS_Utilities

MODULE AtmoIono
  USE EGOPS_Utilities
  IMPLICIT NONE
  CHARACTER(LEN=10), PARAMETER :: ComputeDryAtmModel = 'Dry Atm. Â '

  TYPE AtmModel
    CHARACTER(LEN=LEN(ComputeDryAtmModel)) :: moistDryStr
  END TYPE AtmModel
END MODULE AtmoIono

PROGRAM Main
  USE AtmoIono
  IMPLICIT NONE

  CHARACTER(LEN=100) :: dir
  TYPE(AtmModel) :: model

  dir = dirname('C:/example/path/file.txt')
  PRINT *, 'Directory name (should be empty): ', TRIM(dir)

  model%moistDryStr = ComputeDryAtmModel
  PRINT *, 'Model string: ', TRIM(model%moistDryStr)

END PROGRAM Main