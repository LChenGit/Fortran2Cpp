program ft
  implicit none
  integer :: result

  result = ishft(1, -3)
  print *, "Result of shifting 1 by -3 positions: ", result
end program ft