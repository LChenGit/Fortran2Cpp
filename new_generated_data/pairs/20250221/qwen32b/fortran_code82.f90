program main
  implicit none
  integer :: a(2), b(2)
  integer :: x, y

  a = 1
  b = 0
  x = 1
  y = 0

  call mvbits(a, 0, 1, b, 1)
  call mvbits(x, 0, 1, y, 1)

  if (any(b /= y)) then
    write(*,*) "Test failed: b and y are not equal."
    call exit(1)
  end if

  write(*,*) "Test passed successfully."
end program main

subroutine mvbits(source, src_pos, nbits, dest, dest_pos)
  implicit none
  integer, intent(in) :: source, src_pos, nbits
  integer, intent(inout) :: dest
  integer, intent(in) :: dest_pos

  integer :: mask, extracted_bits, clear_mask

  mask = ((1 << nbits) - 1) << src_pos
  extracted_bits = (source & mask) >> src_pos

  clear_mask = ~(((1 << nbits) - 1) << dest_pos)
  dest = dest & clear_mask

  dest = dest | (extracted_bits << dest_pos)
end subroutine mvbits