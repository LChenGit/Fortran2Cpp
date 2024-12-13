program testSquareNumber
    implicit none
    integer :: testInput, expectedResult, actualResult

    ! Test case 1
    testInput = 5
    expectedResult = 25
    call squareNumber(testInput, actualResult)
    if (actualResult == expectedResult) then
        print *, "Test 1 passed."
    else
        print *, "Test 1 failed."
    endif
    
    ! Test case 2
    testInput = -3
    expectedResult = 9
    call squareNumber(testInput, actualResult)
    if (actualResult == expectedResult) then
        print *, "Test 2 passed."
    else
        print *, "Test 2 failed."
    endif
    
contains

    subroutine squareNumber(inputNumber, result)
        integer, intent(in) :: inputNumber
        integer, intent(out) :: result
        result = inputNumber * inputNumber
    end subroutine squareNumber

end program testSquareNumber