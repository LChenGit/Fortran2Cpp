module array_operations
  implicit none
contains
  subroutine add_arrays(array1, array2, sum_array, size)
    real, dimension(size), intent(in) :: array1, array2
    real, dimension(size), intent(out) :: sum_array
    integer, intent(in) :: size
    integer :: i

    do i = 1, size
       sum_array(i) = array1(i) + array2(i)
    end do
  end subroutine add_arrays
end module array_operations