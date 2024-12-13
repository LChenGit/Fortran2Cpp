module functions
    implicit none
contains
    real function cvmgp(x1, x2, x3)
        real, intent(in) :: x1, x2
        integer, intent(in) :: x3
        if (x3 < 0) then
            cvmgp = x2
        else
            cvmgp = x1
        end if
    end function cvmgp

    real function cvmgz(x1, x2, x3)
        real, intent(in) :: x1, x2
        integer, intent(in) :: x3
        if (x3 < 0) then
            cvmgz = x2
        else
            cvmgz = x1
        end if
    end function cvmgz

    real function cvmgn(x1, x2, x3)
        real, intent(in) :: x1, x2
        integer, intent(in) :: x3
        if (x3 <= 0) then
            cvmgn = x1
        else
            cvmgn = x2
        end if
    end function cvmgn

    real function cvmgt(x1, x2, x3)
        real, intent(in) :: x1, x2
        logical, intent(in) :: x3
        if (x3) then
            cvmgt = x1
        else
            cvmgt = x2
        end if
    end function cvmgt

    real function cvmgm(x1, x2, x3)
        real, intent(in) :: x1, x2
        integer, intent(in) :: x3
        if (x3 <= 0) then
            cvmgm = x2
        else
            cvmgm = x1
        end if
    end function cvmgm
end module functions

program test_fortran
    use functions
    implicit none
    real :: x1, x2
    integer :: x3
    logical :: lx3
    
    x1 = 1.0
    x2 = 2.0
    x3 = -1
    print *, 'cvmgp:', cvmgp(x1, x2, x3)
    x3 = 1
    print *, 'cvmgp:', cvmgp(x1, x2, x3)
    x3 = -1
    print *, 'cvmgz:', cvmgz(x1, x2, x3)
    x3 = 1
    print *, 'cvmgz:', cvmgz(x1, x2, x3)
    x3 = -1
    print *, 'cvmgn:', cvmgn(x1, x2, x3)
    x3 = 1
    print *, 'cvmgn:', cvmgn(x1, x2, x3)
    lx3 = .true.
    print *, 'cvmgt:', cvmgt(x1, x2, lx3)
    lx3 = .false.
    print *, 'cvmgt:', cvmgt(x1, x2, lx3)
    x3 = -1
    print *, 'cvmgm:', cvmgm(x1, x2, x3)
    x3 = 1
    print *, 'cvmgm:', cvmgm(x1, x2, x3)
end program test_fortran