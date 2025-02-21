! utilbd.f90
module utilbd_module
    integer, public :: IU(14)
    integer, public :: NQ, NF, IF(1), JX, JY
    double precision, public :: QX(1), QY(1)

contains
    subroutine initUtilbd()
        IU(1) = 1
        IU(2) = 1
        IU(3) = 10
        IU(4) = 10
        IU(5) = 50
        IU(6) = 2
        IU(7) = 1
        IU(8) = 1
        IU(9) = 1
        IU(10) = 8000
        IU(11) = 0
        IU(12) = 1
        IU(13) = 1000
        IU(14) = 1000

        NQ = 1
        QX(1) = 0.0d0
        QY(1) = 0.0d0
        NF = 1
        IF(1) = 1
        JX = 0
        JY = 0
    end subroutine initUtilbd

    subroutine printValues()
        write (*,*) "IU:", IU
        write (*,*) "NQ, NF, IF, JX, JY:", NQ, NF, IF(1), JX, JY
        write (*,*) "QX, QY:", QX(1), QY(1)
    end subroutine printValues

    function add(x, y) result(res)
        double precision :: x, y, res
        res = x + y
    end function add

end module utilbd_module

program main_program
    use utilbd_module
    implicit none

    call initUtilbd()
    call printValues()

    write (*,*) "Addition test: ", add(5.0d0, 3.0d0)

end program main_program