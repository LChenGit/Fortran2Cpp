! char_pointer_comp_assign.f90
program char_pointer_comp_assign
  implicit none
  type :: dt
     character (len=4), pointer :: scalar
     character (len=4), pointer :: array(:)
  end type dt
  type (dt) :: a 
  character (len=4), target :: scalar_t ="abcd"
  character (len=4), target :: array_t(2) = (/"abcd","efgh"/)

  allocate (a%scalar, a%array(2))
  a%scalar = scalar_t
  if (a%scalar /= "abcd") call abort ()
  a%array = array_t
  if (any(a%array /= (/"abcd","efgh"/))) call abort ()
  deallocate (a%scalar, a%array)

  a%scalar => scalar_t
  if (a%scalar /= "abcd") call abort ()
  a%array => array_t
  if (any(a%array /= (/"abcd","efgh"/))) call abort ()

end program char_pointer_comp_assign