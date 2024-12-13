program testFixmap
  implicit none
  integer, parameter :: numel = 5
  integer :: map(numel) = [0, 2, 0, 4, 0]
  
  call fixmap(numel, map)
  
  do 10 i = 1, numel
     print *, 'map(', i, ') = ', map(i)
10 continue
end program testFixmap

subroutine fixmap(numel, map)
  integer, intent(in) :: numel
  integer, intent(inout) :: map(numel)
  
  do 20 i = 1, numel
     if (map(i) == 0) map(i) = i
20 continue
end subroutine fixmap