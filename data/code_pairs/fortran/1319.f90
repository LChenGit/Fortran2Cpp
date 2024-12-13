SUBROUTINE ZMESS(NUMESS, LESSEL, LESSDL, IDESS, NEESS, NEDSS, IXEESS, IXEDSS, LTEESS, LTSSS, LTSNC, FAC, USESDF)
    INTEGER NUMESS, LESSEL, LESSDL
    INTEGER IDESS(*), NEESS(*), NEDSS(*), IXEESS(*), IXEDSS(*), LTEESS(*), LTSSS(*), LTSNC(*)
    REAL FAC(*)
    LOGICAL USESDF

    INTEGER JESS, JNE, JDF, IDFE, IESS, N, NE, ICNT, ND1, IDFB, JNELST, JDFLST, ND

    IF (NUMESS .LE. 0) RETURN

    JESS = 0
    JNE = 0
    JDF = 0
    IDFE = 0
    DO IESS = 1, NUMESS
        JNELST = JNE
        JDFLST = JDF
        ND1 = IXEDSS(IESS)
        IDFB = ND1
        DO N = 1, NEESS(IESS)
            NE = N + IXEESS(IESS) - 1
            ICNT = LTSNC(NE)
            IDFE = IDFB + ICNT - 1
            IF (LTEESS(NE) .GT. 0) THEN
                JNE = JNE + 1
                LTEESS(JNE) = LTEESS(NE)
                LTSSS(JNE)  = LTSSS(NE)
                LTSNC(JNE)  = LTSNC(NE)
                IF (USESDF) THEN
                    DO ND = IDFB, IDFE
                        JDF = JDF + 1
                        FAC(JDF) = FAC(ND)
                    END DO
                END IF
            END IF
            IDFB = IDFE + 1
        END DO
        N = JNE - JNELST
        IF (N .GT. 0) THEN
            JESS = JESS + 1
            IDESS(JESS) = IDESS(IESS)
            NEESS(JESS) = N
            IXEESS(JESS) = JNELST + 1
            IF (USESDF) THEN
                NEDSS(JESS) = JDF - JDFLST
                IXEDSS(JESS) = JDFLST + 1
            END IF
        END IF
    END DO
    NUMESS = JESS
    LESSEL = JNE
    IF (USESDF) THEN
        IF (IDFE .NE. LESSDL) STOP 'ZMESS: Internal error'
        LESSDL = JDF
    END IF
END SUBROUTINE ZMESS