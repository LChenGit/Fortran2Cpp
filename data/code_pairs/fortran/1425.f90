program mainProgram
  implicit none
  integer :: inputNumber, result

  ! Function declaration
  interface
    function factorial(n) result(fact)
      integer, intent(in) :: n
      integer :: fact
    end function factorial
  end interface

  ! Main program logic
  print *, "Enter a number to calculate factorial: "
  read *, inputNumber
  result = factorial(inputNumber)
  print *, "The factorial of ", inputNumber, " is ", result

contains
  ! Function to calculate factorial
  function factorial(n) result(fact)
    integer, intent(in) :: n
    integer :: fact, i
    fact = 1
    do i = 1, n
      fact = fact * i
    end do
  end function factorial
end program mainProgram