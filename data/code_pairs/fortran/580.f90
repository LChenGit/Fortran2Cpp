! sum_array.f90
program sum_array
  implicit none
  integer, dimension(5) :: numbers = [1, 2, 3, 4, 5]
  integer :: total

  total = sum_array(numbers, 5)
  print *, "Sum is: ", total

contains

  function sum_array(arr, n) result(total)
    integer, dimension(n), intent(in) :: arr
    integer, intent(in) :: n
    integer :: total, i

    total = 0
    do i = 1, n
      total = total + arr(i)
    end do
  end function sum_array

end program sum_array