! t.f90
program t
  integer :: i
  i = 1
  call output_value(i)
  
  i = 2
  call output_value(i)
  
  i = 3
  call output_value(i)
  
contains

  subroutine output_value(i)
    integer, intent(in) :: i
    if (i.eq.1) then
      print *, 1
    else if (i.eq.2) then
      print *, 2
    else
      print *, 3
    end if
  end subroutine output_value
  
end program t