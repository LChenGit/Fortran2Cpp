function f(x) result(res)
    character(len=*), intent(in) :: x
    character(len=len(x)) :: res
    res = x
end function f