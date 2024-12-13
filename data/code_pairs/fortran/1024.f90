subroutine return_and_stop(n)
  integer, intent(in) :: n
  if (n==0) then
     return
  end if
  stop
end subroutine return_and_stop