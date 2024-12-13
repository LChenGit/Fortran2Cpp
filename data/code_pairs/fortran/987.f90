module foo
  implicit none
  type :: t
     character(len=2) :: x
  end type t
end module foo

program main
  use foo
  implicit none
  type(t) :: a
  character(len=3) :: b
  character(len=10) :: line
  
  a%x = 'a'
  write(unit=line, fmt='(A,A)') trim(a%x), "X"
  if (line /= 'aX        ') call abort
  
  b = 'ab'
  write(unit=line, fmt='(A,A)') trim(b), "Y"
  if (line /= 'abY       ') call abort
  
  print *, "All operations succeeded."
end program main