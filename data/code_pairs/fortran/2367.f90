program test
  implicit none
  character(10) :: a(3)
  character(10) :: b(3) = (/ 'Takata ', 'Tanaka ', 'Hayashi' /)
  character(4) :: c = "abcd"

  a = (/ 'Takata ', 'Tanaka ', 'Hayashi' /)
  b = (/ 'abc', 'abc', 'abc' /)
  c = "abcd"

  print *, "Array a:"
  print *, a
  print *, "Array b:"
  print *, b
  print *, "String c:"
  print *, c

end program test