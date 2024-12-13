module good
   implicit none
   type default_initialization
      integer :: x = 42
   end type default_initialization
   type (default_initialization) t
end module good

program test
   use good
   implicit none

   ! Check if the default value is set correctly
   if (t%x /= 42) then
      print *, "Test failed: Initial value of t%x is not 42"
      call abort()
   else
      print *, "Test passed: Initial value of t%x is correct"
   end if

   ! Modify the value and check again
   t%x = 0
   if (t%x /= 0) then
      print *, "Test failed: Modified value of t%x is not 0"
      call abort()
   else
      print *, "Test passed: Modified value of t%x is correct"
   end if
end program test