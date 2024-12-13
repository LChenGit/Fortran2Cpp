program t
  implicit none
  integer :: unitnumber
  character(len=10) :: access = 'sequential'

  open(newunit=unitnumber, file='tmpfile', status='replace', access=access, form='formatted')
  write(unitnumber,*) 'This is a test.'

  close(unitnumber)

  ! Optionally delete the file here if necessary
  ! open(unit=unitnumber, file='tmpfile', status='old')
  ! close(unitnumber, status='delete')
end program t