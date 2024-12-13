subroutine strippath(fnam2, fnam, path, iflag)
  implicit none
  character(len=80) :: fnam2
  character(len=80) :: fnam
  character(len=80) :: path
  integer :: iflag, i

  iflag = 0
  
  do i = 1, len_trim(fnam2)
    if (fnam2(i:i) == '/') then
      iflag = i
    endif
  end do
  
  if (iflag > 0) then
    fnam = fnam2(iflag+1:)
    path = fnam2(1:iflag)
  else
    fnam = fnam2
    path = ""
  endif

end subroutine strippath