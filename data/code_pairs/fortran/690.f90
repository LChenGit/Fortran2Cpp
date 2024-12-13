module add_module
  implicit none
contains
  function add(a, b) result(res)
    integer, intent(in) :: a, b
    integer :: res
    res = a + b
  end function add
end module add_module