MODULE ocean_mod
  IMPLICIT NONE
  LOGICAL :: is_finalized = .FALSE.
CONTAINS
  SUBROUTINE ROMS_finalize
    ! This subroutine finalizes the ROMS environment.
    is_finalized = .TRUE.
    PRINT *, "ROMS_finalize called, environment finalized."
  END SUBROUTINE ROMS_finalize
  
  SUBROUTINE abort(status)
    INTEGER, INTENT(IN) :: status
    CALL ROMS_finalize
    STOP
  END SUBROUTINE abort
END MODULE ocean_mod