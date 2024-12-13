module globalPHMF
  implicit none

  private
  public :: ioutPHMF, iprecision, ndigits, outfile

  integer :: ioutPHMF = 0
  integer :: iprecision = 2
  integer :: ndigits = 7
  character(len=30) :: outfile = 'PreHeadsMF_output.txt'
end module globalPHMF