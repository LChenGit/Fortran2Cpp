module modphonon
  implicit none
  contains
    function square(x) result(res)
      real, intent(in) :: x
      real :: res

      res = x**2
    end function square
end module modphonon