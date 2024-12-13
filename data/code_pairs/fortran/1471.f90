subroutine s1()
  do i = 1,10
    cycle
  end do
  do i = 1,10
    exit
  end do
  outer: do i = 1,10
    cycle
    inner: do j = 1,10
      cycle
    end do inner
    cycle
  end do outer
end subroutine s1