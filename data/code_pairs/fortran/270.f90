! main_program.f90
program main_program
  implicit none
  integer, save :: itmp(3)
  itmp(1) = 3
  if (size(itmp) == 3 .and. itmp(1) == 3) then
     write(*,*) "OK"
  else
     write(*,*) "NG: itmp(3)[*] is illegally allocated or not allocated."
  endif
end program main_program