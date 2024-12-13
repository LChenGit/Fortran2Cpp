! Module containing the subroutine
MODULE MDPIN2Mod
CONTAINS
    SUBROUTINE MDPIN2(TST1, TST2, TST3)
        REAL, INTENT(OUT) :: TST1, TST2, TST3
        TST1 = 1.0
        TST2 = TST1 + 1.E-10
        TST3 = TST2 + 1.E-10
    END SUBROUTINE MDPIN2
END MODULE MDPIN2Mod

! Main program to test the subroutine
PROGRAM TestMDPIN2
    USE MDPIN2Mod
    REAL :: TST1, TST2, TST3

    CALL MDPIN2(TST1, TST2, TST3)

    IF (TST1 == 1.0 .AND. TST2 == TST1 + 1.E-10 .AND. TST3 == TST2 + 1.E-10) THEN
        PRINT *, "Test Passed"
    ELSE
        PRINT *, "Test Failed"
    END IF
END PROGRAM TestMDPIN2