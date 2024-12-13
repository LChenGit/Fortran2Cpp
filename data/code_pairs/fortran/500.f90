program test_q
    implicit none

contains

    subroutine qr(f)
        interface
            subroutine f(x)
                real, intent(in) :: x
            end subroutine f
        end interface
        external f

        call f(5.0)
    end subroutine qr

    subroutine qc(f)
        interface
            subroutine f(x)
                complex, intent(in) :: x
            end subroutine f
        end interface
        external f

        call f((5.0, 0.0))
    end subroutine qc

    subroutine realFunction(x)
        real, intent(in) :: x
        print *, 'Real function called with argument:', x
    end subroutine realFunction

    subroutine complexFunction(x)
        complex, intent(in) :: x
        print *, 'Complex function called with argument:', x
    end subroutine complexFunction

end program test_q

! To test, call qr(realFunction) and qc(complexFunction) within the program scope.