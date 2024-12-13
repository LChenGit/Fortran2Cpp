program test_continuation_lines
  implicit none
  integer :: seconds_in_a_day = 0

  ! Test 1
  seconds_in_a_day = 24*60*60
  if (seconds_in_a_day == 86400) then
     print*, "Test 1 passed."
  else
     print*, "Test 1 failed."
  endif

  ! Test 2
  seconds_in_a_day = 24*60*60 
  if (seconds_in_a_day == 86400) then
     print*, "Test 2 passed."
  else
     print*, "Test 2 failed."
  endif

  ! Test 3: Demonstrating a long string output
  print*, "This is a really long string, that normally would not fit on a single line."
end program