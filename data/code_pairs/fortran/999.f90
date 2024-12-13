program chkbits
  implicit none

  integer :: testResult

  ! Test setting the highest bit
  call testSetHighestBit(testResult)
  if (testResult == 0) then
    print *, "Test for setting the highest bit Passed"
  else
    print *, "Test for setting the highest bit Failed"
  endif

  ! Test clearing the highest bit
  call testClearHighestBit(testResult)
  if (testResult == 0) then
    print *, "Test for clearing the highest bit Passed"
  else
    print *, "Test for clearing the highest bit Failed"
  endif

  ! Test inverting bits
  call testInvertBits(testResult)
  if (testResult == 0) then
    print *, "Test for inverting bits Passed"
  else
    print *, "Test for inverting bits Failed"
  endif

end program chkbits

subroutine testSetHighestBit(result)
  integer, intent(out) :: result
  integer(kind=1) :: i1
  i1 = -1
  if (i1 == -1) then
    result = 0
  else
    result = 1
  endif
end subroutine

subroutine testClearHighestBit(result)
  integer, intent(out) :: result
  integer(kind=1) :: i1
  i1 = 0
  if (i1 == 0) then
    result = 0
  else
    result = 1
  endif
end subroutine

subroutine testInvertBits(result)
  integer, intent(out) :: result
  integer(kind=1) :: i1
  i1 = not(0)
  if (i1 == -1) then
    result = 0
  else
    result = 1
  endif
end subroutine