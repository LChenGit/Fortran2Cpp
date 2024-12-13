program test_format
  implicit none
  character(len=6) :: c
  write (c, '(A, I4, A)') ' ', 1, ' '
  if (c /= '    1 ') then
    print *, 'Test failed'
    call abort
  else
    print *, 'Test passed'
  end if
end program test_format