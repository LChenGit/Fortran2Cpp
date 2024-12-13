module my_module
  implicit none
contains
  function add_numbers(a, b)
    integer :: add_numbers
    integer, intent(in) :: a, b
    add_numbers = a + b
  end function add_numbers
end module my_module