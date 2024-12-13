module myoperator
    contains
        function dadd(arg1, arg2)
            integer :: dadd(2)
            integer, intent(in) :: arg1(2), arg2(2)
            dadd(1) = arg1(1) + arg2(1)
            dadd(2) = arg1(2) + arg2(2)
        end function dadd
end module myoperator