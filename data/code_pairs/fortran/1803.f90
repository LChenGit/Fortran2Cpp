module modreport
    implicit none
    integer :: reportfileu
contains
    subroutine finalizeoutput(reportfileu)
        implicit none
        integer, intent(in) :: reportfileu

        write(reportfileu,*)"</report>"
        close(reportfileu)
    end subroutine finalizeoutput
end module modreport