module char_conversion_functions
  use, intrinsic :: iso_c_binding
  implicit none
contains
  function return_char1(i) result(output) bind(c, name='return_char1')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char1

  function return_char2(i) result(output) bind(c, name='return_char2')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char2

  function return_char3(i) result(output) bind(c, name='return_char3')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char3
end module char_conversion_functions