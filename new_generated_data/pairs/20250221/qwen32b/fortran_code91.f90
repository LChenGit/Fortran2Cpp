program test_boundary_mass_force_matrix2d
    implicit none
    double precision :: FiS, FiN
    double precision, dimension(3,3) :: TT, RN
    double precision, dimension(3,3) :: expected_RN, expected_RN2
    integer :: i

    ! Test case 1
    FiS = 2.0
    FiN = 1.0
    TT = reshape([1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0], [3,3])
    RN = 0.0  ! Properly initialize RN to zeros
    call BoundaryMassForceMatrix2D(FiS, FiN, TT, RN)

    ! Expected results for test case 1
    expected_RN = reshape([&
        2.0*1.0*1.0 + 1.0*1.0*1.0, 0.0, (2.0 - 1.0)*1.0*1.0, &
        0.0, 0.0, 0.0, &
        (2.0 - 1.0)*1.0*1.0, 0.0, 1.0*1.0*1.0 + 2.0*1.0*1.0 &
    ], [3,3])

    ! Check results for test case 1
    do i = 1, 3
        if (any(abs(RN(i,:) - expected_RN(i,:)) > 1e-6)) then
            write(*,*) "Test case 1 failed: assertion failed"
            call exit(1)
        end if
    end do

    ! Print the result for test case 1
    print *, "RN matrix after test case 1:"
    do i = 1, 3
        print *, RN(i, :)
    end do

    ! Test case 2
    FiS = 3.0
    FiN = 2.0
    TT = reshape([2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0], [3,3])
    RN = 0.0  ! Properly initialize RN to zeros
    call BoundaryMassForceMatrix2D(FiS, FiN, TT, RN)

    ! Expected results for test case 2
    expected_RN2 = reshape([&
        3.0*(2.0**2) + 2.0*(2.0**2), 0.0, (3.0 - 2.0)*(2.0**2), &
        0.0, 0.0, 0.0, &
        (3.0 - 2.0)*(2.0**2), 0.0, 2.0*(2.0**2) + 3.0*(2.0**2) &
    ], [3,3])

    ! Check results for test case 2
    do i = 1, 3
        if (any(abs(RN(i,:) - expected_RN2(i,:)) > 1e-6)) then
            write(*,*) "Test case 2 failed: assertion failed"
            call exit(1)
        end if
    end do

    ! Print the result for test case 2
    print *, "RN matrix after test case 2:"
    do i = 1, 3
        print *, RN(i, :)
    end do

    write(*,*) "All tests passed!"
end program test_boundary_mass_force_matrix2d

subroutine BoundaryMassForceMatrix2D(FiS, FiN, TT, RN)
    implicit none
    double precision, intent(in) :: FiS, FiN
    double precision, intent(in), dimension(3,3) :: TT
    double precision, intent(out), dimension(3,3) :: RN

    RN(1,1) = FiS * TT(1,1) * TT(1,1) + FiN * TT(3,3) * TT(3,3)
    RN(1,3) = (FiS - FiN) * TT(1,1) * TT(3,3)
    RN(3,1) = RN(1,3)
    RN(3,3) = FiS * TT(3,3) * TT(3,3) + FiN * TT(1,1) * TT(1,1)
end subroutine BoundaryMassForceMatrix2D