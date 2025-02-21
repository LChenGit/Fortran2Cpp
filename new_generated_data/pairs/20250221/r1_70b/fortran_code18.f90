program matrix_addition_test
    implicit none
    integer :: N = 1000
    real, allocatable :: A(:, :)
    real, allocatable :: B(:, :)
    real, allocatable :: C(:, :)

    ! Allocate memory for matrices
    allocate(A(N, N))
    allocate(B(N, N))
    allocate(C(N, N))

    ! Initialize matrix A with 1.0
    A = 1.0

    ! Initialize matrix B with 2.0
    B = 2.0

    ! Compute C = A + B
    C = A + B

    ! Perform unit tests
    if (C(1, 1) /= 3.0) then
        write (*, *) "Test case 1 failed: C(1,1) should be 3.0"
        call exit(1)
    end if

    if (C(N/2, N/2) /= 3.0) then
        write (*, *) "Test case 2 failed: C(N/2,N/2) should be 3.0"
        call exit(1)
    end if

    if (C(N, N) /= 3.0) then
        write (*, *) "Test case 3 failed: C(N,N) should be 3.0"
        call exit(1)
    end if

    write (*, *) "All tests passed!"

    ! Deallocate memory
    deallocate(A)
    deallocate(B)
    deallocate(C)
end program matrix_addition_test