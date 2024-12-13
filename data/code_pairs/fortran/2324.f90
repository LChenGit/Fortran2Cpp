module matvec_module
  implicit none
contains

  subroutine matvec(n, x, y, nelt, ia, ja, a, isym)
    integer, intent(in) :: n, nelt, ia(*), ja(*), isym
    real(8), intent(in) :: x(*), a(*)
    real(8), intent(out) :: y(n)
    integer :: i, j, l, nd, na

    nd = nelt - n
    if (isym == 0) then
       na = nd / 2
       do i = 1, n
          y(i) = a(nd + i) * x(i)
       end do
       do j = 1, n
          do l = ja(j), ja(j + 1) - 1
             i = ia(l)
             y(i) = y(i) + a(l) * x(j)
          end do
       end do
       do j = 1, n
          do l = ja(j), ja(j + 1) - 1
             i = ia(l)
             y(j) = y(j) + a(l + na) * x(i)
          end do
       end do
    else
       ! Handle symmetric case if required
    endif
  end subroutine matvec

end module matvec_module