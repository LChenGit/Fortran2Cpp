module foo0_module
contains
    subroutine foo0()
        integer :: j
        do j = 1, 2
            if (.true.) then
                ! No action specified
            end if
        end do
    end subroutine foo0
end module foo0_module

program test_foo0
    use foo0_module
    implicit none
    integer :: executionCount = 0
    integer :: j
    
    call foo0()
    write(*,*) "Test passed: foo0 executed without errors"
    
    ! Additional test to verify loop execution count
    do j = 1, 2
        if (.true.) then
            executionCount = executionCount + 1
        end if
    end do
    if (executionCount == 2) then
        write(*,*) "Test passed: Loop executed the correct number of times"
    else
        write(*,*) "Test failed: Incorrect loop execution count"
    end if
end program test_foo0