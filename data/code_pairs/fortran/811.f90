program testProgram
  implicit none
  integer :: output(4), i
  
  ! Calling the test version of foo1 to fill the output array
  call foo1_test(output)
  
  ! Printing the test results
  print*, "Testing foo1..."
  do i = 1, 4
    print*, "output(", i, ") = ", output(i)
  end do
end program testProgram

subroutine foo1_test(output)
  implicit none
  integer, intent(out) :: output(4)
  integer :: i, k, count
  
  count = 1
  do k = 1, 2
    do i = 3, 4
      output(count) = i + k
      count = count + 1
    end do
  end do
end subroutine foo1_test