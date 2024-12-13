module mod1
contains
  function eval(func, x1)
    real :: eval, func, x1
    external :: func
    eval = func(x1)
  end function eval
end module mod1