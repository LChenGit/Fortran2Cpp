! Main program for the Fortran code
program test_mapc2m_latlong
    implicit none

    double precision pi, pi2
    double precision tolerance

    double precision xc, yc, xp, yp, zp
    integer blockno
    double precision expected_xp, expected_yp, expected_zp

    pi = 3.141592653589793d0
    pi2 = 2.0d0 * pi
    tolerance = 1.0d-6

    blockno = 1
    xc = 0.0d0
    yc = 0.0d0
    expected_xp = 1.0d0
    expected_yp = 0.0d0
    expected_zp = 0.0d0

    call mapc2m_latlong(blockno, xc, yc, xp, yp, zp)

    if (abs(xp - expected_xp) > tolerance .or. &
        abs(yp - expected_yp) > tolerance .or. &
        abs(zp - expected_zp) > tolerance) then
        print *, 'Test Case 1 Failed'
    else
        print *, 'Test Case 1 Passed'
    end if

contains

    subroutine mapc2m_latlong(blockno, xc, yc, xp, yp, zp)
        implicit none

        integer blockno
        double precision xc, yc, xp, yp, zp
        double precision deg2rad, xc1, yc1

        deg2rad = pi / 180.d0

        xc1 = deg2rad*xc
        yc1 = deg2rad*yc

        xp = cos(yc1)*cos(xc1)
        yp = cos(yc1)*sin(xc1)
        zp = sin(yc1)
    end subroutine mapc2m_latlong

end program test_mapc2m_latlong