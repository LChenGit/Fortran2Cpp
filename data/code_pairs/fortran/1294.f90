module functions
    implicit none
contains
    function f() result(g)
        integer :: g
        g = 1
    end function f

    recursive function rf() result(g)
        integer :: g
        g = 1
    end function rf
end module functions