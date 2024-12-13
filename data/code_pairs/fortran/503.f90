program main
  implicit none
  integer :: i, nerr, ival
  integer, dimension(10) :: aa
  integer :: me

  me = 1  ! Assuming a specific value for 'me' for this standalone example
  nerr = 0

  do i=1,10
     if (me == 3) then
        aa(i) = 10 - i
     else
        aa(i) = -i * 100
     end if
  end do

  ! Intended mismatches for testing purposes
  if (me == 1) then
      aa(3) = 555
      aa(4) = 666
  end if

  do i=1,10
     if (me == 1 .and. i == 3) then
        ival = 555
     else if (me == 1 .and. i == 4) then
        ival = 666
     else if (me == 3) then
        ival = 10 - i
     else
        ival = -i * 100
     end if

     if (aa(i) /= ival) then
        print *, "Mismatch at i=", i, "with aa(i)=", aa(i), "and ival=", ival
        nerr = nerr + 1
     endif
  end do

  if (nerr == 0) then
     print *, "OK"
  else
     print *, "number of NGs: ", nerr
  end if

end program main