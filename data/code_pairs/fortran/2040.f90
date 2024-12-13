program main
  implicit none
  integer, parameter :: N = 5
  integer :: random_array(N), ans_val, i

  ! Predefined test array for simplicity
  random_array = [100, 200, 300, 400, 500]

  ans_val = 0
  do i=1, N
     ans_val = max(ans_val, random_array(i))
  enddo

  write(*,*) "Maximum Value: ", ans_val
end program main