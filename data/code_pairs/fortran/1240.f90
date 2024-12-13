! Define the function great_rsd
function great_rsd(a, b)
    real :: a
    real :: b
    real :: great_rsd
    
    ! Functionality: returns the sum of a and b
    great_rsd = a + b
end function great_rsd

! Main program to test the great_rsd function
program test_great_rsd
    real :: result
    
    ! Test case 1
    result = great_rsd(1.0, 2.0)
    if (result == 3.0) then
        print *, "Test 1 Passed"
    else
        print *, "Test 1 Failed"
    end if
    
    ! Additional tests can be added here
end program test_great_rsd