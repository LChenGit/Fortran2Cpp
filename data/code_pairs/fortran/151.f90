program test_great_rsd
  implicit none

  ! Test cases for the great_rsd function
  call great_rsd(1, 2)
  call great_rsd(-1, -2)
  call great_rsd(100, 200)

contains

  ! Implementation of great_rsd that prints the sum of two numbers
  subroutine great_rsd(x, y)
    implicit none
    integer, intent(in) :: x, y
    print *, 'Sum of ', x, ' and ', y, ' is ', x + y
  end subroutine great_rsd

end program test_great_rsd