function lenocc(c) result(res)
  character(len=*), intent(in) :: c
  integer :: res, i

  res = len(trim(c)) ! Initially set to the length of the string without trailing spaces
  do i = res, 1, -1
     if (c(i:i) /= ' ') then
        res = i
        return
     endif
  end do
  res = 0
end function lenocc

program testLenocc
  implicit none
  integer :: result

  result = lenocc('hello world  ')
  write(*,*) 'Test 1:', result == 11
  result = lenocc('   ')
  write(*,*) 'Test 2:', result == 0
  result = lenocc('noSpaces')
  write(*,*) 'Test 3:', result == 8

end program testLenocc