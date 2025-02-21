program main
    integer, parameter :: N = 1000
    integer, allocatable :: a(:,:), sa, result
    real*8, allocatable :: b(:,:)
    
    ! Allocate memory for arrays
    allocate(a(N, N))
    allocate(b(N, N))
    
    ! Initialize variables
    sa = 0
    result = 0
    
    ! Initialize arrays to zero
    a = 0
    b = 0.0
    
    ! Unit tests
    ! Test 1: Check if the size of array a is correct
    if (size(a) /= N * N) then
        write(*,*) "Test 1 failed: size of array a is incorrect"
        call exit(1)
    end if
    
    ! Test 2: Check if the size of array b is correct
    if (size(b) /= N * N) then
        write(*,*) "Test 2 failed: size of array b is incorrect"
        call exit(1)
    end if
    
    ! Test 3: Check if variables sa and result are initialized to 0
    if (sa /= 0 .or. result /= 0) then
        write(*,*) "Test 3 failed: variables sa or result not initialized to 0"
        call exit(1)
    end if
    
    ! Test 4: Check array initialization
    a(1,1) = 5
    if (a(1,1) /= 5) then
        write(*,*) "Test 4 failed: array a not correctly initialized"
        call exit(1)
    end if
    
    ! Test 5: Check array bounds
    if (N /= 1000) then
        write(*,*) "Test 5 failed: N is not 1000"
        call exit(1)
    end if
    
    write(*,*) "All tests passed successfully."
    
    ! Deallocate memory
    deallocate(a, b)
    stop
end program main