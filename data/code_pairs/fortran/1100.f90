program testMod
    implicit none
    integer :: result, expected

    result = mod(13, 5)
    expected = 3

    if (result == expected) then
        print *, "Test passed: mod(13, 5) == ", expected
    else
        print *, "Test failed: mod(13, 5) != ", expected, ", got ", result
    end if
end program testMod