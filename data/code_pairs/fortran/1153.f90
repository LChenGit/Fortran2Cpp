subroutine peak(peaksu, peaki, iel, ieltmp, icnt)
  implicit none
  real, intent(in) :: peaki
  real, dimension(3), intent(inout) :: peaksu
  integer, intent(in) :: iel
  integer, dimension(3), intent(inout) :: ieltmp
  integer, intent(inout) :: icnt

  if (peaki.gt.1.0e-05) then
    icnt = icnt + 1
    peaksu(icnt) = peaki
    ieltmp(icnt) = iel
  end if
end subroutine peak