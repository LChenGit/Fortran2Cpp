module mytypes
   implicit none
 contains
   pure integer function get_i ()
     get_i = 13
   end function
end module

program test
  use mytypes
  implicit none
  integer, dimension(get_i()) :: x
  print *, size (x)
end