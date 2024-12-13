program test_upper
    implicit none
    character(len = 20) :: result

    result = Upper("abcdefgh")
    if (trim(result) /= "AB") then
        print *, "Test failed: Expected 'AB', got '", trim(result), "'"
        stop 1
    else
        print *, "Test passed."
    end if

contains

    character(len = 20) function Upper(string)
        character(len = *), intent(in) :: string
        character(len = 2) :: firstTwoChars
        firstTwoChars = string(1:2)
        Upper = adjustl(firstTwoChars)
    end function Upper

end program test_upper