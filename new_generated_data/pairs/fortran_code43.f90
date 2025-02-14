program test_index
    implicit none
    character*5 x
    integer i
    
    x = '12345'
    i = index(x, 'blablabl')
    
    if (i /= 0) then
        write(*, *) "Test failed: index should be 0."
        call exit(1)
    endif
    
    write(*, *) "Test passed: index is correctly 0."
end program test_index