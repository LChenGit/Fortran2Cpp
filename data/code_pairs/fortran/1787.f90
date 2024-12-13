! factorial.f90
module factorial_mod
  implicit none
contains
  function factorial(n) result(fact)
    integer, intent(in) :: n
    integer :: fact, i

    fact = 1
    do i = 1, n
       fact = fact * i
    end do
  end function factorial
end module factorial_mod