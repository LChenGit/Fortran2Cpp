! module.f90
module dec_char_conversion_module
  implicit none
contains
  subroutine assign_values(i, x, str)
    integer, intent(out) :: i
    real, intent(out) :: x
    character(len=10), intent(out) :: str

    i = 42
    x = 3.14
    str = 'Hello'
  end subroutine assign_values
end module dec_char_conversion_module

! test.f90
program dec_char_conversion_test
  use dec_char_conversion_module
  implicit none
  integer :: i
  real :: x
  character(len=10) :: str

  call assign_values(i, x, str)

  print *, 'Integer i = ', i
  print *, 'Real x = ', x
  print *, 'String str = ', str

  if (i == 42) then
    print *, 'Test i passed'
  else
    print *, 'Test i failed'
  end if

  if (x == 3.14) then
    print *, 'Test x passed'
  else
    print *, 'Test x failed'
  end if

  if (str == 'Hello') then
    print *, 'Test str passed'
  else
    print *, 'Test str failed'
  end if
end program dec_char_conversion_test