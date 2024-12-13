MODULE EGOPS_Utilities
CONTAINS
  FUNCTION dirname(fullfilename)
    CHARACTER(LEN=*), INTENT(IN) :: fullfilename
    CHARACTER(LEN=LEN(fullfilename)) :: dirname
    ! Assuming a simplistic implementation for illustration
    dirname = ''  ! Placeholder for actual dirname computation
  END FUNCTION dirname
END MODULE EGOPS_Utilities

MODULE AtmoIono
  CHARACTER(LEN=10), PARAMETER :: ComputeDryAtmModel = 'Dry Atm.  '

  TYPE AtmModel
    CHARACTER (LEN=LEN(ComputeDryAtmModel)) :: moistDryStr
  END TYPE AtmModel
END MODULE AtmoIono

PROGRAM AtmoIonoSphere
  USE EGOPS_Utilities
  USE AtmoIono
  IMPLICIT NONE

  TYPE(AtmModel) :: model
  CHARACTER(LEN=100) :: path, dir

  path = "/path/to/somefile.ext"
  dir = dirname(path)

  PRINT *, "Directory name: ", dir
  PRINT *, "Model default string: ", TRIM(model%moistDryStr)
END PROGRAM AtmoIonoSphere