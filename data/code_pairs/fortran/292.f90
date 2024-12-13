module modreport
  implicit none
  integer :: tests, nfailed, npassed
  integer :: reportfileu
  character(len=256) :: reportfilename
  character(len=256) :: testplan_name
  character(len=256) :: tdirectory
  character(len=20) :: testunitname, inputf, outputf
end module modreport