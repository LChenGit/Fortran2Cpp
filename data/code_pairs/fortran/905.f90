MODULE gipaw_version
  IMPLICIT NONE
  CHARACTER (LEN=12) :: gipaw_svn_revision = "392"
END MODULE gipaw_version

PROGRAM testGipawVersion
  USE gipaw_version
  IMPLICIT NONE
  
  WRITE(*,*) "Testing gipaw_version module..."
  IF (gipaw_svn_revision == "392") THEN
    WRITE(*,*) "Test passed: gipaw_svn_revision is correct."
  ELSE
    WRITE(*,*) "Test failed: gipaw_svn_revision is incorrect."
  END IF
END PROGRAM testGipawVersion