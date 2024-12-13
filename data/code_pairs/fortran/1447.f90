program fortran_test
    use, intrinsic :: iso_c_binding
    implicit none
    character(kind=c_char, len=256) :: arg = "Hello from Fortran" // c_null_char
    type(c_ptr) :: c

    interface
        subroutine print_string(str) bind(C, name="print_string")
            import :: c_char
            implicit none
            character(kind=c_char), intent(in) :: str(*)
        end subroutine print_string
    end interface

    c = c_loc(arg)
    call print_string(c)
end program fortran_test