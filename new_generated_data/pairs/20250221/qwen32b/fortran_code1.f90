program testbyte
  integer(1) :: ii = 7
  call foo(ii)
  
  ! Unit test
  if (ii .ne. 7) then
    write(*,*) "Test case failed: assertion failed"
    call exit(1)
  end if
end program testbyte

subroutine foo(ii)
  integer(1) ii
  byte b
  b = ii
  call bar(ii, b)
end subroutine foo

subroutine bar(ii, b)
  integer(1) ii
  byte b
  if (b .ne. ii) then
     STOP 1
  end if
end subroutine bar