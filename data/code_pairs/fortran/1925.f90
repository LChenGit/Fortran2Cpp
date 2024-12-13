module sorting_utilities
  implicit none
contains
  function is_sorted_dble(vec) result(out)
    double precision, intent(in) :: vec(:)
    integer :: out, i
    out = 0
    do i = 2, size(vec)
       if (vec(i) < vec(i - 1)) then
          out = i
          exit
       end if
    end do
  end function is_sorted_dble
end module sorting_utilities