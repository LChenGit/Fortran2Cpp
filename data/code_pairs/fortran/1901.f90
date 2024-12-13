module sum_module
contains
  function compute_sum(n) result(sum)
    implicit none
    integer, intent(in) :: n
    integer :: sum
    integer :: i

    sum = 0
    do i = 1, n
       sum = sum + i
    end do
  end function compute_sum
end module sum_module