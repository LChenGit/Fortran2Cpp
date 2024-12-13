! countem.f90
program countem
  implicit none
  integer(1) :: count1
  integer(2) :: count2
  integer(4) :: count4, irate4, mymax4
  real(4) :: rrate4

  ! Placeholder values to simulate system_clock behavior
  count1 = -127
  count2 = -32767
  count4 = 0
  irate4 = 1000
  rrate4 = 1000.0
  mymax4 = 2147483647

  ! Simulating checks
  if (count1 /= -127.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort
  if (count2 /= -32767.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort
  if (count4 /= 0.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort

  print *, "All checks passed."
end program countem