program main
  implicit none
  integer, dimension(5) :: data = [1, 2, 3, 4, 5]
  integer :: maxValue

  ! Find the maximum value
  maxValue = maxval(data)
  print *, "Maximum Value: ", maxValue
  
  ! Test
  call test

contains
  subroutine test
    integer, dimension(5) :: testData = [-5, -4, -3, -2, -1]
    integer :: testMax

    testMax = maxval(testData)
    if (testMax .eq. -1) then
       print *, "Test PASS"
    else
       print *, "Test FAIL"
    endif
  end subroutine test
end program main