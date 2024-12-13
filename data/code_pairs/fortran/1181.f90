program test
    implicit none

    ! Test variables
    integer :: n

    ! Test subroutine call
    n = 5
    call foo(n)

contains

    subroutine foo(n)
        integer, intent(in) :: n
        character(len=id(n)) :: a
        print *, 'Array length as per id:', len(a)
        a = 'test'
        print *, 'Subroutine foo called with n =', n
    end subroutine foo

    pure function id(a)
        integer, intent(in) :: a
        print *, 'ID function called with:', a
        id = a
    end function id

end program test