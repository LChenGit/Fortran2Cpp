program p_010
  use, intrinsic :: iso_fortran_env
  implicit none
  integer(int64) :: i, n, sum
  character(len=*), parameter :: fileName = 'output.txt'
  
  sum = 2
  loop: do n = 3, 2000000, 2
     do i = 3, int(sqrt(real(n))), 2
        if (mod(n, i) == 0) then
            cycle loop
        endif
     end do
     sum = sum + n
  end do loop
  
  ! Write the sum to a file for testing purposes
  open(unit=10, file=fileName, status='replace', action='write')
  write(10, *) sum
  close(10)
end program p_010