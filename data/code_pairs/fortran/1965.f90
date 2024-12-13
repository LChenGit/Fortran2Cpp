program sum_array
  implicit none
  integer :: i, sum, N
  integer, allocatable :: arr(:)

  N = 5
  allocate(arr(N))
  sum = 0

  ! Initialize the array
  do i=1, N
     arr(i) = i
  end do

  ! Calculate the sum
  do i=1, N
     sum = sum + arr(i)
  end do

  ! Output the result
  print *, "Sum = ", sum

  ! Unit Test
  call test_sum_array(sum)

contains

  subroutine test_sum_array(actual_sum)
    implicit none
    integer, intent(in) :: actual_sum
    integer :: expected_sum

    expected_sum = 15  ! The sum of numbers 1 to 5

    if (actual_sum == expected_sum) then
       print *, "Test Passed: Sum = ", actual_sum
    else
       print *, "Test Failed: Expected Sum = ", expected_sum, " but got ", actual_sum
    end if
  end subroutine test_sum_array

end program sum_array