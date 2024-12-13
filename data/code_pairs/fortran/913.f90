program us_recl
  implicit none
  real, dimension(5) :: array = [5.4321, 5.4321, 5.4321, 5.4321, 5.4321]
  integer :: istatus
  open(unit=10, file='data.bin', form='unformatted', access='sequential')
  write(10, iostat=istatus) array
  close(10)
  if (istatus /= 0) then
    stop 1
  else
    open(unit=11, file='data.bin', status='replace', action='delete')
    close(11)
  endif
end program us_recl