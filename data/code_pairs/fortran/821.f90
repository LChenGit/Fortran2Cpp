module digit_module
  implicit none
contains
  real(kind=8) function digit(string, istart) 
    implicit none
    integer, intent(in) :: istart
    character(len=*), intent(in) :: string
    integer :: i0, i9, ineg, ipos, idot, ispc, l, idig, i, n, j
    real(kind=8) :: c1, c2, deciml
    logical :: sign

    i0 = ichar('0')
    i9 = ichar('9')
    ineg = ichar('-')
    ipos = ichar('+')
    idot = ichar('.')
    ispc = ichar(' ')
    
    c1 = 0.0d0
    c2 = 0.0d0
    sign = .TRUE.
    l = len(string)
    idig = 0

    do i = istart, l
      n = ichar(string(i:i))
      if (n >= i0 .and. n <= i9) then
        idig = idig + 1
        c1 = c1 * 10.0d0 + n - i0
      else if (n == ineg .or. n == ipos .or. n == ispc) then
        if (n == ineg) sign = .FALSE.
      else if (n == idot) then
        exit
      else
        exit
      endif
    end do

    deciml = 1.0d0
    do j = i + 1, l
      n = ichar(string(j:j))
      if (n >= i0 .and. n <= i9) then
        deciml = deciml / 10.0d0
        c2 = c2 + (n - i0) * deciml
      else if (n /= ispc) then
        exit
      endif
    end do

    digit = c1 + c2
    if (.not. sign) digit = -digit
  end function digit
end module digit_module