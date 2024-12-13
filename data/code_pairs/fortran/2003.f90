! sum_module.f90
module sum_module
  implicit none
contains
  function sumArray(arr) result(total)
    integer, intent(in) :: arr(:)
    integer :: total
    total = sum(arr)
  end function sumArray
end module sum_module