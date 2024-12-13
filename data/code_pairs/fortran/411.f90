module types_module
    implicit none

    type :: ipdt(k)
        integer, kind :: k
        integer(kind=k) :: x
    end type ipdt

    type :: rpdt(k)
        integer, kind :: k
        real(kind=k) :: x
    end type rpdt

    type :: zpdt(k)
        integer, kind :: k
        complex(kind=k) :: x
    end type zpdt

    type :: lpdt(k)
        integer, kind :: k
        logical(kind=k) :: x
    end type lpdt
end module types_module

program test_parameterized_types
    use types_module
    use, intrinsic :: iso_fortran_env, only: int8, int16, int32, int64, real32, real64
    implicit none

    type(ipdt(int32)) :: i4
    type(rpdt(real32)) :: a4
    type(zpdt(real32)) :: z4
    type(lpdt(int8)) :: l1

    i4%x = 42
    print *, 'i4%x = ', i4%x

    a4%x = 3.14_real32
    print *, 'a4%x = ', a4%x

    z4%x = (2.0_real32, 3.0_real32)
    print *, 'z4%x = ', z4%x

    l1%x = .true.
    print *, 'l1%x = ', l1%x

end program test_parameterized_types