program main
implicit none

call test(.true.)
call test(.false.)

contains

integer function hello()
 hello = 42
end function hello

subroutine test(first)
 logical :: first
 integer :: i
 procedure(integer), pointer :: x => null()

 if(first) then
  if(associated(x)) call abort()
  x => hello
 else
  if(.not. associated(x)) call abort()
  i = x()
  if(i /= 42) call abort()
 end if
 print *, "Test passed."
end subroutine test

end program main