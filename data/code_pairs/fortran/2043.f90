MODULE mock_dependencies
  IMPLICIT NONE
  LOGICAL, PUBLIC :: twfcollect = .TRUE.
  LOGICAL, PUBLIC :: do_coulomb = .TRUE.
  INTEGER, PUBLIC :: iuwfc = 1
  INTEGER, PUBLIC :: iubar = 2

CONTAINS

  SUBROUTINE close_buffer(id, action)
    INTEGER, INTENT(IN) :: id
    CHARACTER(len=*), INTENT(IN) :: action
    PRINT *, "close_buffer called with id=", id, " action=", action
  END SUBROUTINE close_buffer

END MODULE mock_dependencies

MODULE close_gwq_module
  USE mock_dependencies, ONLY: twfcollect, do_coulomb, iuwfc, iubar, close_buffer
  IMPLICIT NONE

CONTAINS

  SUBROUTINE close_gwq(flag)
    LOGICAL, INTENT(IN) :: flag
    IF (twfcollect) THEN
      CALL close_buffer(iuwfc, 'delete')
    ELSE
      CALL close_buffer(iuwfc, 'keep')
    END IF

    IF (flag .AND. do_coulomb) THEN
      CALL close_buffer(iubar, 'keep')
    ELSE
      CALL close_buffer(iubar, 'keep')
    END IF
  END SUBROUTINE close_gwq

END MODULE close_gwq_module