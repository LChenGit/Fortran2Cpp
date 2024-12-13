program collatz_program
  implicit none
  integer :: b, p
  call computeCollatz()
  call testCollatz()
contains

  subroutine computeCollatz()
    use, intrinsic :: iso_fortran_env
    implicit none
    integer(int64) :: n, m
    integer :: i
    integer, parameter :: max_num = 1000000
    integer :: a(max_num)
    a = 0
    p = 0

    do n = 1, max_num
       m = n
       i = 1
       do while (m /= 1)
          if (mod(m, 2) == 0) then
             m = m / 2
             if (m <= max_num) then
                if (a(m) /= 0) then
                   i = i + a(m)
                   exit
                end if
             end if
          else
             m = m * 3 + 1
          end if
          i = i + 1
       end do
       a(n) = i
       if (i > p) then
          b = n
          p = i
       end if
    end do
    print *, "solution: ", b, ", count=", p
  end subroutine computeCollatz

  subroutine testCollatz()
    integer :: length
    call calculateCollatzLength(13, length)
    if (length == 10) then
       print *, "Test Passed: Length for n=13 is correct."
    else
       print *, "Test Failed: Length for n=13 is incorrect. Got", length
    end if
  end subroutine testCollatz

  subroutine calculateCollatzLength(n, length)
    use, intrinsic :: iso_fortran_env
    implicit none
    integer(int64), intent(in) :: n
    integer(int64) :: m
    integer, intent(out) :: length
    m = n
    length = 1
    do while (m /= 1)
       if (mod(m, 2) == 0) then
          m = m / 2
       else
          m = m * 3 + 1
       end if
       length = length + 1
    end do
  end subroutine calculateCollatzLength

end program collatz_program