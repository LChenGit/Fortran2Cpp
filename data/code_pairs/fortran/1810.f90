program main
    type tt
        integer :: a
        double precision :: b
        character(len=10) :: c
    end type tt

    type(tt) :: a
    a%a = 1
    a%b = 20.0D0
    a%c = "ccc"

    print *, a%a, a%b, a%c
end program main