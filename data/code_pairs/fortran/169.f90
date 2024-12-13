program main
  implicit none
  integer(8) :: foo(4294967296_8:4294967297_8)
  integer(8) :: bar(-4294967297_8:-4294967296_8)
  integer(8) :: lb, ub
  bar = 42
  foo = bar
  lb = lbound(foo, dim = 1, kind = 8)
  ub = ubound(foo, dim = 1, kind = 8)
  print *, 'bounds of foo - ', lb, ':', ub
end program main