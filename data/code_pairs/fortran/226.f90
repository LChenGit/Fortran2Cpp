program titles_program
  implicit none
  character(len=3) :: titles(18)
  integer :: i

  ! Initialize titles array
  titles = ['SMA', 'PMA', 'SRA', 'PRA', 'PER', &
            'INC', 'EPO', 'ZPT', 'ALB', 'NL1', &
            'NL2', 'NL3', 'NL4', 'ECW', 'ESW', &
            'TED', 'VOF', 'DIL']
  
  ! Example usage: print all titles
  do i = 1, 18
     print *, 'Title(', i, '): ', titles(i)
  end do
end program titles_program