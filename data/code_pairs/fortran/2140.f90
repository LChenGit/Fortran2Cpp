MODULE ppm_module_util_invert_list
    IMPLICIT NONE
CONTAINS
    SUBROUTINE ppm_util_invert_list(inputArray, outputArray)
        INTEGER, INTENT(IN) :: inputArray(:)
        INTEGER, INTENT(OUT) :: outputArray(SIZE(inputArray))
        INTEGER :: i

        DO i = 1, SIZE(inputArray)
            outputArray(SIZE(inputArray) - i + 1) = inputArray(i)
        END DO
    END SUBROUTINE ppm_util_invert_list
END MODULE ppm_module_util_invert_list