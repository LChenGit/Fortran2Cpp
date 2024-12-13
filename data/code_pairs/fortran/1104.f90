program test
  implicit none
  integer :: n, result

  n = 100
  result = parallel_sum(n)

  if (result /= n) then
    print *, "Error: The sum did not match the expected value."
    call abort
  else
    print *, "Test Passed: Sum is ", result
  endif
contains
  function parallel_sum(n) result(var)
    integer, intent(in) :: n
    integer :: var, i

    var = 0
    !$acc parallel loop reduction(+:var)
    do i = 1, n
       var = var + 1
    end do
    !$acc end parallel loop
  end function parallel_sum
end program test