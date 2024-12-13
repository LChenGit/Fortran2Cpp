MODULE ppm_module_data
    INTEGER, PARAMETER :: ppm_param_alloc_fit = 1
    INTEGER, PARAMETER :: ppm_param_alloc_fit_preserve = 2
    INTEGER, PARAMETER :: ppm_param_alloc_grow = 3
    INTEGER, PARAMETER :: ppm_param_alloc_grow_preserve = 4
    INTEGER, PARAMETER :: ppm_param_dealloc = 5
END MODULE ppm_module_data

MODULE ppm_module_error
    INTEGER, PARAMETER :: ppm_error_error = -1
    INTEGER, PARAMETER :: ppm_err_argument = 1
    CONTAINS
    SUBROUTINE ppm_error(err_code, caller, message, line, info)
        INTEGER, INTENT(IN) :: err_code
        CHARACTER(LEN=*), INTENT(IN) :: caller, message
        INTEGER, INTENT(IN) :: line
        INTEGER, INTENT(INOUT) :: info
        PRINT *, "Error in ", TRIM(caller), ": ", TRIM(message), " at line ", line
        info = ppm_error_error
    END SUBROUTINE ppm_error
END MODULE ppm_module_error

PROGRAM test_ppm_alloc_argcheck
    USE ppm_module_data
    USE ppm_module_error
    IMPLICIT NONE
    INTEGER :: info
    INTEGER, DIMENSION(2) :: ldl = [1, 2]

    CALL ppm_alloc_argcheck("TestCaller", ldl, ppm_param_alloc_fit, 2, info)
    IF (info == 0) THEN
        PRINT *, "Test 1 Passed"
    ELSE
        PRINT *, "Test 1 Failed"
    END IF

    CALL ppm_alloc_argcheck("TestCaller", ldl, -1, 2, info) ! Invalid iopt
    IF (info /= 0) THEN
        PRINT *, "Test 2 Passed"
    ELSE
        PRINT *, "Test 2 Failed"
    END IF

CONTAINS
    SUBROUTINE ppm_alloc_argcheck(caller, ldl, iopt, dimension, info)
        USE ppm_module_data
        USE ppm_module_error
        CHARACTER(LEN=*)               , INTENT(IN)   :: caller
        INTEGER, DIMENSION(:)          , INTENT(IN)   :: ldl
        INTEGER                        , INTENT(IN)   :: iopt
        INTEGER                        , INTENT(IN)   :: dimension
        INTEGER                        , INTENT(INOUT)  :: info
        INTEGER :: i
        info = 0
        IF (iopt /= ppm_param_alloc_fit           .AND. &
            iopt /= ppm_param_alloc_fit_preserve  .AND. &
            iopt /= ppm_param_alloc_grow          .AND. &
            iopt /= ppm_param_alloc_grow_preserve .AND. &
            iopt /= ppm_param_dealloc) THEN
            CALL ppm_error(ppm_err_argument, caller, 'unknown iopt', __LINE__, info)
            RETURN
        ENDIF
        DO i = 1, dimension
            IF (ldl(i) < 0) THEN
                CALL ppm_error(ppm_err_argument, caller, 'ldl() must be >= 0', __LINE__, info)
                RETURN
            ENDIF
        ENDDO
    END SUBROUTINE ppm_alloc_argcheck
END PROGRAM test_ppm_alloc_argcheck