! Fortran program to demonstrate file operations
program fileOpsFortran
  implicit none
  integer :: iounit
  character(len=100) :: line

  ! Create and open a file for writing
  open(unit=iounit, file='fortran_testfile', status='replace', action='write')
  ! Write a line to the file
  write(iounit,*) 'Test'
  ! Close the file
  close(iounit)

  ! Open the file for reading
  open(unit=iounit, file='fortran_testfile', status='old', action='read')
  ! Read the line from the file
  read(iounit,*) line
  ! Print the line read from the file
  print *, "Read from file:", line
  ! Close the file
  close(iounit)

  ! Delete the file
  call execute_command_line('rm fortran_testfile')
end program fileOpsFortran