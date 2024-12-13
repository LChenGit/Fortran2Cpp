program test_random_number
    implicit none
    real :: r(1,5)
    integer :: i
    
    ! Generate Random Numbers
    CALL RANDOM_NUMBER(r)
    
    ! Print generated numbers
    print *, 'Generated random numbers (within the range [0, 1]):'
    do i = 1, 5
        print *, r(1,i)
    end do
    
end program test_random_number