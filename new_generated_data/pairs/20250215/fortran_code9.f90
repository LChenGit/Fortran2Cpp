PROGRAM Example
    INTEGER :: NL = 5
    INTEGER :: NMG = 2
    REAL :: CL(10)
    
    ! Initialize array with 1.0s
    CL = 1.0
    
    IF (NL > 4 .AND. NMG > 1) THEN
        PRINT *, "Inside the condition"
        NL = NL - 1
        PRINT *, "Modified NL value: ", NL
        CL(NL - 1) = CL(NL - 1) / CL(NL + 1)
    END IF
    
    PRINT *, "Final CL values:"
    PRINT *, CL
    PRINT *, "Final NL value:", NL
END PROGRAM Example