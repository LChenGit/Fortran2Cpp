MODULE PERMUTE_ELEMENTS_LOGICAL1D__genmod
    CONTAINS
    SUBROUTINE PERMUTE_ELEMENTS_LOGICAL1D(ARRAY_TO_PERMUTE, TEMP_ARRAY, PERM, NSPEC)
        INTEGER(KIND=4), INTENT(IN) :: NSPEC
        LOGICAL(KIND=4), INTENT(INOUT) :: ARRAY_TO_PERMUTE(NSPEC)
        LOGICAL(KIND=4), INTENT(INOUT) :: TEMP_ARRAY(NSPEC)
        INTEGER(KIND=4), INTENT(IN) :: PERM(NSPEC)
        INTEGER :: i
        DO i = 1, NSPEC
            TEMP_ARRAY(i) = ARRAY_TO_PERMUTE(PERM(i))
        END DO
        ARRAY_TO_PERMUTE = TEMP_ARRAY
    END SUBROUTINE PERMUTE_ELEMENTS_LOGICAL1D
END MODULE PERMUTE_ELEMENTS_LOGICAL1D__genmod