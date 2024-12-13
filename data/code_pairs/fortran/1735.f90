module ldaU_hp
  implicit none
contains
  ! Function to sum elements of an array
  function sum_array(arr) result(total)
    real, intent(in) :: arr(:)
    real :: total
    total = sum(arr)
  end function sum_array
end module ldaU_hp