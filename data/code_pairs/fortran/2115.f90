program add_numbers
  implicit none
  integer :: number1, number2, sum

  ! Assuming fixed input values for demonstration
  number1 = 5
  number2 = 7

  sum = number1 + number2

  write(*,*) 'The sum is: ', sum
end program add_numbers