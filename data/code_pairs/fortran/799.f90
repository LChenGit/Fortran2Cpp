program foo
  integer :: a(3,3), l, ll
  a = 0

  do l=1,3
     do ll=1,3
        a(l,ll) = 2
     enddo
  enddo

  if (any(a(1:3,1:3).ne.2)) STOP 1

end program foo