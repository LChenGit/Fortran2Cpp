program dec_comparison_character_1
  implicit none
  character(len=1) :: a = 'A', b = 'B'
  if (a < b) then
    print *, "A is less than B"
  else
    print *, "A is not less than B"
  endif
end program dec_comparison_character_1