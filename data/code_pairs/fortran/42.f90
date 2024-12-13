program prog
    implicit none
    real, dimension(2) :: data
    integer, dimension(2) :: nums
    
    ! Initialize the arrays
    nums = [12, 34]
    data = [1.2, 3.4]
    
    ! Perform operations
    call perform_operations(nums, data)
    
end program prog

subroutine perform_operations(nums, data)
    implicit none
    real, intent(in) :: data(2)
    integer, intent(in) :: nums(2)
    
    ! Print the data with the specified format
    print '(f3.1,x,f3.1)', data
    print '(i3,x,i3)', nums

end subroutine perform_operations