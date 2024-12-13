subroutine foo0()
  integer :: j
  do j = 1, 2
    if (.true.) then
      print *, "Loop iteration: ", j
    end if
  end do
end subroutine