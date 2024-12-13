program where_15
   implicit none
   integer :: a(5)
   integer :: b(5)
   integer :: i

   a = (/1, 2, 3, 4, 5/)
   b = (/0, 0, 0, 0, 0/)

   where (a /= 1)
      b = 2
   end where

   print *, "b = ", b
end program where_15