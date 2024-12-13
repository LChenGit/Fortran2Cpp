! This file can be named main.f90
program main
    print *, "Testing logicalfunc:"
    call test_logicalfunc()

contains
    logical function logicalfunc()
        logicalfunc = .true.
    end function logicalfunc

    subroutine test_logicalfunc()
        if (logicalfunc() .eqv. .true.) then
            print *, "Test passed: logicalfunc() is true"
        else
            print *, "Test failed: logicalfunc() is not true"
        endif
    end subroutine test_logicalfunc

end program main