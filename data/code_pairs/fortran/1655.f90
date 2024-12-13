module sort_utils
  implicit none
contains
  pure function is_sorted_asc_real(x) result(sorted)
    logical :: sorted
    real, intent(in) :: x(:)
    integer :: i

    sorted = .true.  ! Default to true, changes to false if unsorted pair found
    do i = 2, size(x)
       if (x(i - 1) > x(i)) then
          sorted = .false.
          return
       end if
    end do
  end function is_sorted_asc_real
end module sort_utils