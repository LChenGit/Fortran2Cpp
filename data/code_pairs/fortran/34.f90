module eapVarApp
contains
    function f(x)
        real :: x
        real :: f
        real :: j, k, l
        j = x
        k = g(j*j)
        l = j * g(j * j * j)
        f = k
    end function f

    function g(x)
        real :: x
        real :: g
        g = x
    end function g

    function h(x)
        real :: x
        real :: h
        h = f(x)
    end function h
end module eapVarApp