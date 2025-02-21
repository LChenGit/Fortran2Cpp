subroutine gapcon(ak, d, flowm, temp, predef, time, coords, area, ciname, slname, msname, noel, node, npred, kstep, kinc)
    implicit none

    character(len=80) :: ciname, slname, msname
    integer :: noel, node, npred, kstep, kinc
    real*8 :: ak(5), d(2), flowm(2), temp(2), predef(2, *), time(*), coords(3), area

    ! Example implementation: Modify predef based on input arrays
    predef(1, 1) = ak(1) + d(1)
    predef(2, 1) = flowm(1) + temp(1)
end subroutine gapcon

program test_gapcon
    implicit none

    ! Test Case 1: Basic functionality test
    block
        real*8 :: ak(5) = [1.0, 2.0, 3.0, 4.0, 5.0]
        real*8 :: d(2) = [10.0, 20.0]
        real*8 :: flowm(2) = [100.0, 200.0]
        real*8 :: temp(2) = [300.0, 400.0]
        real*8 :: predef(2, 1) = 0.0
        real*8 :: time(3) = [1.0, 2.0, 3.0]
        real*8 :: coords(3) = [0.0, 0.0, 0.0]
        real*8 :: area = 100.0
        character(len=80) :: ciname = "TestCiname"
        character(len=80) :: slname = "TestSlname"
        character(len=80) :: msname = "TestMsname"
        integer :: noel = 1
        integer :: node = 2
        integer :: npred = 3
        integer :: kstep = 4
        integer :: kinc = 5

        call gapcon(ak, d, flowm, temp, predef, time, coords, area, ciname, slname, msname, noel, node, npred, kstep, kinc)

        ! Check outputs
        if (predef(1, 1) /= 11.0) then
            write(*, *) "Test Case 1 failed: predef(1,1) is incorrect."
            call exit(1)
        end if
        if (predef(2, 1) /= 400.0) then
            write(*, *) "Test Case 1 failed: predef(2,1) is incorrect."
            call exit(1)
        end if
    end block

    ! Test Case 2: Boundary values test
    block
        real*8 :: ak(5) = [0.0, 0.0, 0.0, 0.0, 0.0]
        real*8 :: d(2) = [0.0, 0.0]
        real*8 :: flowm(2) = [0.0, 0.0]
        real*8 :: temp(2) = [0.0, 0.0]
        real*8 :: predef(2, 1) = 0.0
        real*8 :: time(3) = [0.0, 0.0, 0.0]
        real*8 :: coords(3) = [0.0, 0.0, 0.0]
        real*8 :: area = 0.0
        character(len=80) :: ciname = ""
        character(len=80) :: slname = ""
        character(len=80) :: msname = ""
        integer :: noel = 0
        integer :: node = 0
        integer :: npred = 0
        integer :: kstep = 0
        integer :: kinc = 0

        call gapcon(ak, d, flowm, temp, predef, time, coords, area, ciname, slname, msname, noel, node, npred, kstep, kinc)

        ! Check outputs
        if (predef(1, 1) /= 0.0) then
            write(*, *) "Test Case 2 failed: predef(1,1) is incorrect."
            call exit(1)
        end if
        if (predef(2, 1) /= 0.0) then
            write(*, *) "Test Case 2 failed: predef(2,1) is incorrect."
            call exit(1)
        end if
    end block

    write(*, *) "All tests passed!"
end program test_gapcon