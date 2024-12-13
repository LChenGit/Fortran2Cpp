module greatRSDMod
    implicit none
contains
    subroutine great_rsd(a, b)
        integer, intent(in) :: a, b
        print *, "Called great_rsd with", a, "and", b, ". Sum is:", a + b
    end subroutine great_rsd
end module greatRSDMod