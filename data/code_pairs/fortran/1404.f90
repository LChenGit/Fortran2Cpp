subroutine nidentll(x, px, n, id)
      implicit none
      integer n, id, n2, m
      integer*8 x(n), px
      id = 0
      if (n .eq. 0) return
      n2 = n + 1
      do
         m = (n2 + id) / 2
         if (px .ge. x(m)) then
            id = m
         else
            n2 = m
         endif
         if ((n2 - id) .eq. 1) return
      enddo
end subroutine nidentll