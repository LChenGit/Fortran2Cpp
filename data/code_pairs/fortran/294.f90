module great_ne_module
contains
    subroutine great_ne(a, b)
        integer, intent(in) :: a, b
        if (a /= b) then
            print *, "great_ne:", a, "and", b, "are not equal."
        else
            print *, "great_ne:", a, "and", b, "are equal."
        endif
    end subroutine great_ne
end module great_ne_module