module great_module
contains
    subroutine great(arg1, arg2)
        implicit none
        character(len=*), intent(in) :: arg1, arg2
        print *, trim(arg1), "and", trim(arg2), "are in 'great' subroutine."
    end subroutine great
end module great_module