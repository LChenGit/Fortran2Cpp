program example
  implicit none
  integer :: output

  output = calculate_sum(10)
  print *, "The sum is", output

contains
  function calculate_sum(n) result(sum)
    implicit none
    integer, intent(in) :: n
    integer :: sum, i

    sum = 0
    do i = 1, n
      sum = sum + i
    end do
  end function calculate_sum

end program example