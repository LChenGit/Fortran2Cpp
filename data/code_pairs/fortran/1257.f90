module sum_module
  implicit none
contains
  function sum_array(array, n) result(total)
    integer, intent(in) :: n
    integer, intent(in) :: array(n)
    integer :: total, i
    
    total = 0
    do i = 1, n
       total = total + array(i)
    end do
  end function sum_array
end module sum_module