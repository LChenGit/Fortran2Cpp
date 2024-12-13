module mod
    integer :: i = 42
end module mod

program test
    use mod
    print *, i
end program test