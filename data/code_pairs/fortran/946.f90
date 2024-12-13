SUBROUTINE ST_LCUC(string, outstr, iret)
    CHARACTER*(*) string, outstr
    INTEGER iret, isize, j, i
    iret = 0
    outstr = string
    isize = LEN_TRIM(outstr)
    
    DO i = 1, isize
        IF ((outstr(i:i) .GE. 'a') .AND. (outstr(i:i) .LE. 'z')) THEN
            j = ICHAR(outstr(i:i))
            j = j - 32
            outstr(i:i) = CHAR(j)
        ENDIF
    END DO
END SUBROUTINE ST_LCUC