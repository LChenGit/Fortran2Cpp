PROGRAM TestFortran
    CHARACTER*10 A
    CHARACTER*8 B
    A = 'gfortran  '
    B = 'rocks!  '
    CALL T(A,B)

CONTAINS

    SUBROUTINE T(A,B)
        CHARACTER*(*) A,B
        IF(LEN(A)/=10) CALL abort()
        IF(LEN(B)/=8) CALL abort()
    END SUBROUTINE T

END PROGRAM TestFortran