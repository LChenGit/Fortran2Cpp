module m
    implicit none
    type :: T
        real :: expectedScalar
    contains
        procedure :: FCheck
        procedure :: FCheckArr
        generic :: Check => FCheck, FCheckArr
    end type T

contains

    subroutine FCheck(this, X)
        class(T), intent(inout) :: this
        real, intent(in) :: X
        if (abs(X - this%expectedScalar) > 0.0001) then
            print *, "Value does not match the expected scalar within tolerance."
            stop 1
        end if
    end subroutine FCheck

    subroutine FCheckArr(this, X)
        class(T), intent(inout) :: this
        real, dimension(:), intent(in) :: X
        integer :: i
        do i = 1, size(X)
            this%expectedScalar = i - 1.0
            call this%FCheck(X(i))
        end do
    end subroutine FCheckArr

end module m

program test
    use m
    implicit none

    type(T) :: Tester
    real :: vec(6) = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0]
    Tester%expectedScalar = 2.0

    call Tester%Check(2.0)
    print *, "Single value check passed."

end program test