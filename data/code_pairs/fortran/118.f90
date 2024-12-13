module string_manipulation
  implicit none
contains
  subroutine convert_case (string, direction)
    character(len=*), intent(inout) :: string
    integer, intent(in) :: direction
    integer :: i, upper_to_lower, len_string
    
    upper_to_lower = iachar("a") - iachar("A")
    len_string = len_trim(string)
    
    do i = 1, len_string
       select case (string(i:i))
       case ('A':'Z')
          if (direction == 0) string(i:i) = achar(iachar(string(i:i)) + upper_to_lower)
       case ('a':'z')
          if (direction == 1) string(i:i) = achar(iachar(string(i:i)) - upper_to_lower)
       end select
    end do
  end subroutine convert_case
end module string_manipulation