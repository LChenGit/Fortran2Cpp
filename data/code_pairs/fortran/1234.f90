! Define the COMMON block in a separate file or at the beginning of your program
COMMON /CKSTRT/ NMM, NKK, NII, MXSP, MXTB, MXTP, NCP, NCP1, &
                 NCP2, NCP2T, NPAR, NLAR, NFAR, NLAN, NFAL, NREV, &
                 NTHB, NRLT, NWL, NRNU, NORD, MXORD, IcMM, IcKK, &
                 IcNC, IcPH, IcCH, IcNT, IcNU, IcNK, IcNS, IcNR, &
                 IcLT, IcRL, IcRV, IcWL, IcFL, IcFO, IcKF, IcTB, &
                 IcKN, IcKT, IcRNU, IcORD, IcKOR, NcAW, NcWT, NcTT, &
                 NcAA, NcCO, NcRV, NcLT, NcRL, NcFL, NcKT, NcWL, &
                 NcRU, NcRC, NcPA, NcKF, NcKR, NcRNU, NcKOR, NcK1, &
                 NcK2, NcK3, NcK4, NcI1, NcI2, NcI3, NcI4

! Test program
PROGRAM testCKSTRT
    IMPLICIT NONE
    ! Declare the variables in the COMMON block
    INTEGER NMM, NKK, NII, MXSP, MXTB, MXTP, NCP, NCP1, NCP2, NCP2T, NPAR
    ! You can continue declaring other variables as required

    ! Initialize one of the variables for testing
    NMM = 1

    ! Modify and test the variable
    NMM = NMM + 1
    IF (NMM == 2) THEN
        PRINT *, 'Test Passed for NMM'
    ELSE
        PRINT *, 'Test Failed for NMM'
    END IF
END PROGRAM testCKSTRT