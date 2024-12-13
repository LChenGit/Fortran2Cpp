module test1_mod
  implicit none
contains
  pure function f(x) result(res)
    integer, intent(in) :: x
    integer :: res
    res = 2*x + 1
  end function f

  function test2(x) result(r)
    integer, intent(in) :: x
    character(len=f(x)) :: r
    integer :: i
    do i = 1, len(r)
      r(i:i) = achar(mod(i,26)+65) ! Generate characters from A to Z in a loop
    end do
  end function test2
end module test1_mod

program test_program
  use test1_mod
  implicit none
  character(:), allocatable :: result

  result = test2(10)
  if (len(result) /= 21) then
    print *, "Test failed for test2 with input 10. Expected length: 21, Got:", len(result)
  else
    print *, "Test passed for test2 with input 10."
  endif
end program test_program