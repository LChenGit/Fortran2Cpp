subroutine stlest(nleft, nright, h)
  integer nleft, nright
  double precision h
  
  h = max(dble(nleft), dble(nright))
  
end subroutine stlest