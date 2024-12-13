program test
    implicit none
    type tt
        integer :: a
        integer, pointer :: b
    end type
    integer, target :: i
    integer, pointer :: j
    integer, pointer :: k
    type(tt) :: x

    NULLIFY(j, k, x%b)

    ! Check and print results for simple "tests"
    if (.not. associated(j)) then
        print *, "Test j passed"
    else
        print *, "Test j failed"
    end if

    if (.not. associated(k)) then
        print *, "Test k passed"
    else
        print *, "Test k failed"
    end if

    if (.not. associated(x%b)) then
        print *, "Test x%b passed"
    else
        print *, "Test x%b failed"
    end if
end program test