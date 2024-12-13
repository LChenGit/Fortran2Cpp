program intrinsic_merge
   implicit none
   integer, dimension(3) :: a, b
   integer :: i
   logical, dimension(3) :: condition

   a = (/-1, 2, 3/)
   b = (/0, 0, 0/)

   i = 5
   if (merge(-1, 1, i > 3) /= -1) call abort
   i = 1
   if (merge(-1, 1, i >= 3) /= 1) call abort

   condition = a >= 0
   b = merge(a, 0, condition)
   if (any(b /= (/0, 2, 3/))) call abort
end program intrinsic_merge