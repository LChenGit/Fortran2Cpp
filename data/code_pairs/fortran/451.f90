module data_mod
    implicit none
contains
    function addTwoNumbers(a, b) result(c)
        implicit none
        integer, intent(in) :: a, b
        integer :: c

        c = a + b
    end function addTwoNumbers
end module data_mod