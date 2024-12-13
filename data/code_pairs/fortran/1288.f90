module avg_module
  implicit none
contains
  function avg(a) result(average)
    integer, intent(in) :: a(:)
    integer :: average
    average = sum(a) / size(a)
  end function avg
end module avg_module