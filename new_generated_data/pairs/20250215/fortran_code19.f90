subroutine binint(IA, NPIX, NLINES, INVAL, IDX, IDY, X, Y, Z, W, NBIN)
    integer*2 IA(NPIX, NLINES)
    double precision X(*), Y(*), Z(*), W(*)
    integer NPIX, NLINES, INVAL, IDX, IDY, NBIN

    NBIN = 0
    do JMIN = 1, NLINES, IDY
        JMAX = min(JMIN + IDY - 1, NLINES)
        do IMIN = 1, NPIX, IDX
            IMAX = min(IMIN + IDX - 1, NPIX)
            sum = 0.0
            npt = 0
            ix = 0
            iy = 0
            do J = JMIN, JMAX
                do I = IMIN, IMAX
                    if (IA(I,J) .ne. INVAL) then
                        sum = sum + IA(I,J)
                        npt = npt + 1
                        ix = ix + I
                        iy = iy + J
                    end if
                end do
            end do
            if (npt >= 1) then
                NBIN = NBIN + 1
                X(NBIN) = real(IX) / npt
                Y(NBIN) = real(IY) / npt
                Z(NBIN) = sum / npt
                W(NBIN) = sqrt(real(npt))
            end if
        end do
    end do
    return
end subroutine binint

program test_binint
    implicit none

    integer*2, dimension(2,2) :: ia
    integer npix, nlines, inval, idx, idy, nbin
    double precision, dimension(3) :: x, y, z, w
    double precision, dimension(3) :: expected_x = [1.0, 1.0, 2.0]
    double precision, dimension(3) :: expected_y = [1.0, 2.0, 2.0]
    double precision, dimension(3) :: expected_z = [1.0, 3.0, 4.0]
    double precision, dimension(3) :: expected_w = [1.0, 1.0, 1.0]
    logical :: all_valid

    integer :: i

    ! Initialize input parameters
    npix = 2
    nlines = 2
    inval = -1
    idx = 1
    idy = 1

    ! Initialize IA array
    ia = reshape([1, -1, 3, 4], [2,2])

    ! Call the BININT subroutine
    call binint(ia, npix, nlines, inval, idx, idy, x, y, z, w, nbin)

    ! Check if the number of bins matches the expected count
    if (nbin /= 3) then
        write(*, *) "Test failed: Incorrect number of bins."
        stop
    end if

    ! Check each element for equality within a small tolerance
    all_valid = .true.
    do i = 1, nbin
        if (abs(x(i) - expected_x(i)) > 1e-9) all_valid = .false.
        if (abs(y(i) - expected_y(i)) > 1e-9) all_valid = .false.
        if (abs(z(i) - expected_z(i)) > 1e-9) all_valid = .false.
        if (abs(w(i) - expected_w(i)) > 1e-9) all_valid = .false.
    end do

    ! Output the test result
    if (all_valid) then
        write(*, *) "All tests passed!"
    else
        write(*, *) "Test failed!"
    end if

end program test_binint