program main
  implicit none
  integer :: N, s, result
  integer, allocatable :: a(:)
  integer :: i
  
  N = 1000
  allocate(a(N))

  do i=1, N
     a(i) = i
  enddo
         
  s = 0
  do i=1, N
     s = s + a(i)
  enddo
  
  result = 0
  if(s /= 500500) then
     result = -1
  endif
  
  if(result == 0) then
     write(*,*) "PASS"
  else
     write(*,*) "ERROR"
     stop 1
  endif

  deallocate(a)
end program main