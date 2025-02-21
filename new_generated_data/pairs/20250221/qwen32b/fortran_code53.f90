module vector_module
    implicit none

    type vector_R4P
        real :: x, y, z
    end type vector_R4P

    interface operator(+)
        module procedure vector_addition
    end interface

contains

    type(vector_R4P) function vector_addition(a, b)
        type(vector_R4P), intent(in) :: a, b
        vector_addition%x = a%x + b%x
        vector_addition%y = a%y + b%y
        vector_addition%z = a%z + b%z
    end function vector_addition

    real function magnitude(v)
        type(vector_R4P), intent(in) :: v
        magnitude = sqrt(v%x**2 + v%y**2 + v%z**2)
    end function magnitude

end module vector_module

program volatile_doctest
    use vector_module
    implicit none

    type(vector_R4P) :: ex_R4P, ey_R4P, ez_R4P, pt
    real :: mag_pt

    ex_R4P = vector_R4P(1.0, 0.0, 0.0)
    ey_R4P = vector_R4P(0.0, 1.0, 0.0)
    ez_R4P = vector_R4P(0.0, 0.0, 1.0)

    pt = ex_R4P + ey_R4P + ez_R4P
    mag_pt = magnitude(pt)

    print "(L1)", 4.0 > mag_pt

    if (4.0 <= mag_pt) then
        write(*,*) "Test case failed: assertion failed"
        call exit(1)
    end if

end program volatile_doctest