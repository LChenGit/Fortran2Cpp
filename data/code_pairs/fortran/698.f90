! Assuming Fortran interfaces with C for environment variable functions.
module env_var_mod
    use, intrinsic :: iso_c_binding, only: c_char, c_int, c_null_char
    implicit none
    interface
        subroutine setenv(name, value, overwrite) bind(C, name="setenv")
            import :: c_char, c_int
            character(kind=c_char), intent(in) :: name(*), value(*)
            integer(c_int), value, intent(in) :: overwrite
        end subroutine setenv

        function getenv(name) result(value) bind(C, name="getenv")
            import :: c_char, c_null_char
            character(kind=c_char), intent(in) :: name(*)
            character(kind=c_char), pointer :: value
        end function getenv
    end interface
end module env_var_mod

program test_environment_variables
    use env_var_mod
    implicit none
    character(kind=c_char), target :: retrieved_value(:)
    character(kind=c_char), pointer :: value_ptr

    call setenv("UVM_TESTNAME"//c_null_char, "uex_ve_multicore_test"//c_null_char, 1)
    call setenv("SW_TESTNAME"//c_null_char, "UEX.basic_multicore_test"//c_null_char, 1)

    ! Check UVM_TESTNAME
    value_ptr => getenv("UVM_TESTNAME"//c_null_char)
    if (associated(value_ptr)) then
        print *, "UVM_TESTNAME is set correctly."
    else
        print *, "UVM_TESTNAME is not set correctly."
    endif

    ! Check SW_TESTNAME
    value_ptr => getenv("SW_TESTNAME"//c_null_char)
    if (associated(value_ptr)) then
        print *, "SW_TESTNAME is set correctly."
    else
        print *, "SW_TESTNAME is not set correctly."
    endif
end program test_environment_variables