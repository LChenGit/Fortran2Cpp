program formatting_check
    implicit none
    character(len=10) :: c1, c2
    real(kind=8) :: r
    r = 1.0
    write(c1,'(E9.2)') r
    write(c2,'(D9.2)') r

    if (trim(adjustl(c1)) .ne. "0.10E+01") then
        print *, "Check failed for c1"
        stop
    end if
    if (trim(adjustl(c2)) .ne. "0.10D+01") then
        print *, "Check failed for c2"
        stop
    end if
    print *, "Fortran: All checks passed."
end program formatting_check