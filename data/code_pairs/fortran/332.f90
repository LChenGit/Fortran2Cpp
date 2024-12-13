program main
  implicit none
  integer :: iounit, ios
  character(len=10) :: a

  open(newunit=iounit, file='tmpfile', status='replace', action='write')
  write(iounit,*) 'Test'
  close(iounit)
  
  ! Deleting the file, assuming a Unix-like system
  call execute_command_line('rm tmpfile')
  
end program main