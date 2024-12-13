MODULE MOD_AnalyzeEquation
  IMPLICIT NONE

CONTAINS

  SUBROUTINE DefineParametersAnalyzeEquation()
  IMPLICIT NONE
  END SUBROUTINE DefineParametersAnalyzeEquation

  SUBROUTINE InitAnalyzeEquation()
  IMPLICIT NONE
  END SUBROUTINE InitAnalyzeEquation

  SUBROUTINE AnalyzeEquation(Time)
    IMPLICIT NONE
    REAL, INTENT(IN) :: Time
  END SUBROUTINE AnalyzeEquation

  SUBROUTINE FinalizeAnalyzeEquation()
  IMPLICIT NONE
  END SUBROUTINE FinalizeAnalyzeEquation

END MODULE MOD_AnalyzeEquation