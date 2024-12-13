function char2type(char)
  character, intent(in) :: char
  integer :: char2type

  select case (char)
    case ('E', 'e')
      char2type = 1
    case default
      char2type = -1234
  end select
end function