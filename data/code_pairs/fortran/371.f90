module sorting_module
  implicit none
contains
  pure subroutine interchange_sort_dec_real(vec)
    real, intent(inout) :: vec(:)
    integer :: i, j
    real :: swap_value

    do i = 1, size(vec) - 1
       do j = i + 1, size(vec)
          if (vec(i) < vec(j)) then
             swap_value = vec(i)
             vec(i) = vec(j)
             vec(j) = swap_value
          end if
       end do
    end do
  end subroutine interchange_sort_dec_real
end module sorting_module