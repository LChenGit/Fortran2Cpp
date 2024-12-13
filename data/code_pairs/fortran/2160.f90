PROGRAM TestNWHSEL
    INTEGER :: NPTIMS
    INTEGER, DIMENSION(5) :: IPTIMS
    LOGICAL, DIMENSION(10) :: WHOTIM
    INTEGER :: result

    ! Initialize test data
    NPTIMS = 5
    IPTIMS = (/ 2, 4, 6, 8, 10 /)
    WHOTIM = (/ .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE. /)

    ! Call the function
    result = NWHSEL(NPTIMS, IPTIMS, WHOTIM)

    ! Print the result
    PRINT *, 'Result: ', result

END PROGRAM TestNWHSEL

INTEGER FUNCTION NWHSEL(NPTIMS, IPTIMS, WHOTIM)
    INTEGER :: NPTIMS
    INTEGER, DIMENSION(*) :: IPTIMS
    LOGICAL, DIMENSION(*) :: WHOTIM
    INTEGER :: I

    NWHSEL = 0
    DO I = 1, NPTIMS
        IF (WHOTIM(IPTIMS(I))) THEN
            NWHSEL = NWHSEL + 1
        END IF
    END DO

    RETURN
END FUNCTION NWHSEL