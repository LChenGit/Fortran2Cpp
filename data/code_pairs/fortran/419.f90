! writecvg.f90
subroutine writecvg(istep, iinc, icutb, iit, ne, ne0, ram, qam, cam, uam, ithermal)
    implicit none

    integer :: istep, iinc, icutb, iit, ne, ne0, ithermal
    double precision, dimension(*) :: ram, qam, cam, uam
    double precision :: residforce, corrdisp, residflux, corrtemp

    if (ithermal .eq. 2) then
        residforce = 0.d0
        corrdisp = 0.d0
    else
        if (abs(qam(1)) .lt. 1.d-30) then
            if (abs(ram(1)) .lt. 1.d-30) then
                residforce = 1.d-30
            else
                residforce = 1.d30
            end if
        else
            residforce = ram(1) / qam(1) * 100.d0
        end if

        if (abs(uam(1)) .lt. 1.d-30) then
            if (abs(cam(1)) .lt. 1.d-30) then
                corrdisp = 1.d-30
            else
                corrdisp = 1.d30
            end if
        else
            corrdisp = cam(1) / uam(1) * 100.d0
        end if
    end if

    if (ithermal .le. 1) then
        residflux = 0.d0
        corrtemp = 0.d0
    else
        if (abs(qam(2)) .lt. 1.d-30) then
            if (abs(ram(2)) .lt. 1.d-30) then
                residflux = 1.d-30
            else
                residflux = 1.d30
            end if
        else
            residflux = ram(2) / qam(2) * 100.d0
        end if
        if (abs(uam(2)) .lt. 1.d-30) then
            if (abs(cam(2)) .lt. 1.d-30) then
                corrtemp = 1.d-30
            else
                corrtemp = 1.d30
            end if
        else
            corrtemp = cam(2) / uam(2) * 100.d0
        end if
    end if

    print *, istep, iinc, icutb+1, iit, ne-ne0, residforce, corrdisp, residflux, corrtemp
end subroutine

! Main program to test the subroutine
program test_writecvg
    implicit none
    integer, parameter :: ne = 2
    double precision :: ram(ne) = [0.1d0, 0.2d0]
    double precision :: qam(ne) = [0.1d0, 0.2d0]
    double precision :: cam(ne) = [0.1d0, 0.2d0]
    double precision :: uam(ne) = [0.1d0, 0.2d0]

    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 0)
    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 1)
    call writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 2)
end program test_writecvg