program main
    use, intrinsic :: iso_fortran_env, only: stdout => output_unit
    implicit none
    
    type :: t1
        integer :: a1 = 1
    end type t1
    
    type, extends(t1) :: t2
        integer :: a2 = 2
    end type t2
    
    type, extends(t2) :: t3
        integer :: a3 = 3
    end type t3
    
    type(t3) :: x3
    integer :: i
    
    i = x3%a2
    print *, "x3%a2: ", i
    
    i = x3%a1
    print *, "x3%a1: ", i
    
end program main