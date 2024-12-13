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
    character(len=:), allocatable :: r
    integer :: len_r, i

    len_r = f(x) ! Determine the length of r based on function f
    allocate(character(len=len_r) :: r) ! Allocate r with the calculated length

    do i = 1, len_r
      r(i:i) = achar(mod(i, 32) + iachar('@'))
    end do
  end function test2
end module test1_mod

program test_program
  use test1_mod
  implicit none
  character(len=:), allocatable :: chr
  character(len=21) :: expected = "ABCDEFGHIJKLMNOPQRSTU"
  integer :: i

  chr = test2(10) ! Call test2 to generate the string

  if (len(chr) /= 21) then
    print *, "Length check failed."
    stop
  end if

  do i = 1, len(chr)
    if (chr(i:i) /= expected(i:i)) then
      print *, "Content check failed."
      stop
    end if
  end do

  print *, "Fortran tests passed successfully."
end program test_program