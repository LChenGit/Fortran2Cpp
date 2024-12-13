subroutine getindx(n, min, siz, loc, index, inflag)
    implicit none
    
    integer, intent(in) :: n
    real*8, intent(in) ::  min, siz, loc
    integer, intent(out) :: index 
    logical, intent(out) :: inflag

    index = int( (loc - min) / siz + 1.5 )

    if(index < 1) then
        index  = 1
        inflag = .FALSE. 
    else if(index > n) then
        index  = n
        inflag = .FALSE. 
    else
        inflag = .TRUE. 
    end if
end subroutine getindx

program test_getindx
    implicit none
    
    integer :: n, index
    real*8 :: min, siz, loc
    logical :: inflag

    ! Test Case 1
    n = 10
    min = 0.0
    siz = 1.0
    loc = 5.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 1: ", index, inflag

    ! Test Case 2
    loc = -1.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 2: ", index, inflag

    ! Test Case 3
    loc = 11.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 3: ", index, inflag
end program test_getindx