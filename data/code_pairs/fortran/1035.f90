module m1
   implicit none
contains
   subroutine bar
      print *, "bar executed"
   end subroutine bar

   subroutine bar_none(i)
      integer :: i
      print *, "bar_none executed with i =", i
   end subroutine bar_none

   subroutine none_bar(x)
      real :: x
      print *, "none_bar executed with x =", x
   end subroutine none_bar
end module m1