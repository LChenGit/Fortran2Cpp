! Original Fortran Program
program tester
  implicit none
  character(50) cname, fred
  integer kk
  
  fred='1234567890123456789012345678901234567890'
  kk=len_trim(fred)
  cname=fred(5:kk)
  print *, kk, cname
end program tester