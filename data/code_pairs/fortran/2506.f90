module mymod
contains
    function myadd(d, e) result(f)
        implicit none
        integer, intent(in) :: d, e
        integer :: f

        f = d + e
    end function myadd
end module mymod

program main
    use mymod
    implicit none

    ! No main logic for demonstration, as focus is on testing
end program main