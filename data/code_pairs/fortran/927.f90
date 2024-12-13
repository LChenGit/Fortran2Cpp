! Fortran function definition
integer function args_loc(array, n, elt)
    integer, intent(in) :: n
    character(len=*), intent(in) :: elt
    character(len=*), intent(in) :: array(n)
    
    integer :: i
    
    do i = 1, n
        if (trim(array(i)) == elt) then
            args_loc = i
            return
        endif
    end do
    args_loc = 0
end function args_loc

! Fortran unit test code
program test_args_loc
    implicit none
    character(len=6), dimension(3) :: testArray
    integer :: result

    testArray = ['apple ', 'banana', 'cherry']

    ! Test 1: Element is in the array
    result = args_loc(testArray, 3, 'banana')
    print *, 'Test 1 (Found): ', result == 2

    ! Test 2: Element is not in the array
    result = args_loc(testArray, 3, 'orange')
    print *, 'Test 2 (Not Found): ', result == 0
end program test_args_loc