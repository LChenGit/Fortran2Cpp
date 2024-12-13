program main
  integer, parameter :: N=10
  integer :: random_array(N), ans_val
  integer :: a(N), sa, result
  real :: tmp(N)
  integer :: i

  call random_seed()
  call random_number(tmp)
  do i=1, N
     random_array(i) = int(tmp(i) * 10000)
  end do

  do i=1, N
     a(i) = random_array(i)
  end do

  ans_val = 0
  do i=1, N
     ans_val = ior(ans_val, random_array(i))
  end do

  sa = 0
  do i=1, N
     sa = ior(sa, a(i))
  end do

  if( sa /= ans_val ) then
     result = -1
  else
     result = 0
  end if

  if( result == 0 ) then
     print *, "PASS"
  else
     print *, "ERROR"
     stop 1
  end if

end program main