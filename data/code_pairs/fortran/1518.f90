module math_operations
  implicit none
contains
  function addTwoNumbers(a, b) result(sum)
    integer, intent(in) :: a, b
    integer :: sum

    sum = a + b
  end function addTwoNumbers
end module math_operations