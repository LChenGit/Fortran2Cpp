! ppm_module_mg_prolong.f90
MODULE ppm_module_mg_prolong
IMPLICIT NONE
CONTAINS
    SUBROUTINE SinglePrecision2D()
        PRINT *, "Single Precision 2D functionality called"
    END SUBROUTINE SinglePrecision2D
    
    SUBROUTINE DoublePrecision2D()
        PRINT *, "Double Precision 2D functionality called"
    END SUBROUTINE DoublePrecision2D
    
    SUBROUTINE SinglePrecision3D()
        PRINT *, "Single Precision 3D functionality called"
    END SUBROUTINE SinglePrecision3D
    
    SUBROUTINE DoublePrecision3D()
        PRINT *, "Double Precision 3D functionality called"
    END SUBROUTINE DoublePrecision3D
END MODULE ppm_module_mg_prolong

PROGRAM Main
    USE ppm_module_mg_prolong
    IMPLICIT NONE
    
    CALL SinglePrecision2D()
    CALL DoublePrecision2D()
    CALL SinglePrecision3D()
    CALL DoublePrecision3D()
END PROGRAM Main