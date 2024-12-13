module my_functions
  implicit none
  contains

  ! Define the damaxf function within a module
  REAL*8 function damaxf(n, dx, incx)
    implicit none
    double precision, intent(in) :: dx(*)
    integer, intent(in) :: n, incx
    integer :: i, ix
    double precision :: dtemp

    damaxf = 0.0d0
    if (n < 1 .or. incx <= 0) return

    damaxf = abs(dx(1))
    if (incx == 1) then
      do i = 2, n
        dtemp = abs(dx(i))
        if (dtemp > damaxf) then
          damaxf = dtemp
        endif
      end do
    else
      ix = 1
      do i = 2, n
        ix = ix + incx
        dtemp = abs(dx(ix))
        if (dtemp > damaxf) then
          damaxf = dtemp
        endif
      end do
    endif
  end function damaxf
end module my_functions