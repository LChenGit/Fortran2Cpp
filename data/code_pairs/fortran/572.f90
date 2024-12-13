program main
  implicit none
  character(len=10) :: testString = "Hello"
  integer :: expected_length, actual_length

  expected_length = 5
  actual_length = len_trim(testString)

  call testLength(actual_length, expected_length)
end program main

subroutine testLength(actual_length, expected_length)
  implicit none
  integer, intent(in) :: actual_length, expected_length

  if (actual_length == expected_length) then
     print *, "Fortran Test PASSED."
  else
     print *, "Fortran Test FAILED."
  end if
end subroutine testLength