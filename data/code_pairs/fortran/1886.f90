subroutine fsub3(arg, res)
  implicit none
  integer :: arg, res

  write(*,*) 'fsub3 called'
  res = arg * 4
end subroutine fsub3