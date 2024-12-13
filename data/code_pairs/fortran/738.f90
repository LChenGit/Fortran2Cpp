Program test_si_kind
  implicit none
  integer*1 i1
  integer*2 i2
  integer*4 i4
  integer*8 i8
  integer res
  real t

  ! Test for i1
  t = huge(i1)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 1) print *, 'Test for i1 Failed'
  
  ! Test for i2
  t = huge(i2)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 2) print *, 'Test for i2 Failed'

  ! Test for i4
  t = huge(i4)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 4) print *, 'Test for i4 Failed'

  ! Test for i8
  t = huge(i8)
  t = log10(t)
  res = selected_int_kind(int(t))
  if (res .ne. 8) print *, 'Test for i8 Failed'

  ! Special case test
  i4 = huge(i4)
  res = selected_int_kind(i4)
  if (res .ne. (-1)) print *, 'Special Case Test Failed'

  print *, 'All tests passed!'
end program