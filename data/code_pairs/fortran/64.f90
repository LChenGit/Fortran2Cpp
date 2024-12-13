module pr94329_mod
  implicit none
contains
  subroutine pr94329 (s, t)
    real :: s
    real, dimension(:,:) :: t
    integer :: i, j
    do i = 1,3
      do j = 1,3
        s = t(i,j)
      end do
    end do
  end subroutine pr94329
end module pr94329_mod