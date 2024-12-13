module bad
   implicit none
   type :: default_initialization
      integer :: x = 42
   end type default_initialization
   type(default_initialization) :: t
end module bad