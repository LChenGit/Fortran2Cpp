module math_utils
  implicit none
contains
  function add(a, b) result(c)
    integer, intent(in) :: a, b
    integer :: c

    c = a + b
  end function add
end module math_utils