! m_ezcu_knl.f90
module m_ezcu_knl
    implicit none
contains
    function square(x) result(y)
        real, intent(in) :: x
        real :: y
        
        y = x * x
    end function square
end module m_ezcu_knl