module set_tides_mod
  implicit none
contains
  function add_two_numbers(a, b) result(c)
    integer, intent(in) :: a, b
    integer :: c

    c = a + b
  end function add_two_numbers
end module set_tides_mod