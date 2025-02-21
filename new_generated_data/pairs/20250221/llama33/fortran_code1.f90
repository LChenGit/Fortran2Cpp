program testbyte
  implicit none
  integer(1) :: ii = 7
  call foo(ii)

  ! Unit tests
  if (ii .ne. 7) then
    write(*,*) "Test case 1 failed: assertion failed"
    call exit(1)
  end if

  ii = 5
  call foo(ii)
  if (ii .ne. 5) then
    write(*,*) "Test case 2 failed: assertion failed"
    call exit(1)
  end if

  ii = -128
  call foo(ii)
  if (ii .ne. -128) then
    write(*,*) "Test case 3 failed: assertion failed"
    call exit(1)
  end if

  ii = 127
  call foo(ii)
  if (ii .ne. 127) then
    write(*,*) "Test case 4 failed: assertion failed"
    call exit(1)
  end if

  write(*,*) "All unit tests passed"

contains

  subroutine foo(ii)
    integer(1), intent(inout) :: ii
    byte :: b
    b = ii
    call bar(ii,b)
  end subroutine foo

  subroutine bar(ii,b)
    integer(1), intent(in) :: ii
    byte, intent(in) :: b
    if (b .ne. ii) then
       stop 1
    end if
  end subroutine bar

end program testbyte