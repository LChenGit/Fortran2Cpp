program main
  implicit none
  integer :: a, b, x, y

  ! Initialize variables
  a = 1
  b = 0
  x = 1
  y = 0

  ! Call mvbits subroutine to move bits
  call mvbits(a, 0, 1, b, 1)
  call mvbits(x, 0, 1, y, 1)

  ! Check if the results are equal
  if (b /= y) then
    write(*,*) "Test case failed: assertion failed"
    call exit(1)
  end if

contains

  ! mvbits subroutine definition
  subroutine mvbits(from, from_pos, length, to, to_pos)
    implicit none
    integer, intent(in) :: from, from_pos, length
    integer, intent(inout) :: to
    integer, intent(in) :: to_pos

    integer :: mask, bits

    ! Compute mask and extract bits
    mask = ishft(ishft(1, length) - 1, from_pos)
    bits = ishft(iand(from, mask), -from_pos)

    ! Clear the corresponding bits in the destination
    if (length == 0) then
      to = to
    else
      to = ishft(to, -(to_pos - from_pos))  ! Shift destination left
      to = ishft(to, (to_pos - from_pos))  ! Shift back to original position, clearing intermediate bits
    end if

    ! Move bits to the new position
    to = ior(to, ishft(bits, to_pos))
  end subroutine mvbits

end program main