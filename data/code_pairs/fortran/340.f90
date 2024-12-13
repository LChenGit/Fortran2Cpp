module m1
   implicit none
contains
   subroutine bar
      print *, "In bar"
   end subroutine

   subroutine bar_none(i)
      integer :: i
      print *, "In bar_none with i =", i
   end subroutine

   subroutine none_bar(x)
      real :: x
      print *, "In none_bar with x =", x
   end subroutine
end module