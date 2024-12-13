program main
  implicit none
  integer :: max_val, i, j, max_pal, prod

  max_val = 999
  max_pal = 1
  do i = 1, max_val
     do j = i, max_val
        prod = i * j
        if (is_pal(prod)) then
           max_pal = max(prod, max_pal)
        endif
     enddo
  enddo
  write(*,*) "Max palindrome: ", max_pal
  
  ! Unit Tests
  call test_is_pal_and_main()

contains

  pure function is_pal(targ) result(is_pal_res)
    integer, intent(in) :: targ
    logical :: is_pal_res
    integer :: reversed, original, remainder, temp_targ
    
    original = targ
    reversed = 0
    temp_targ = targ
    
    do while (temp_targ /= 0)
       remainder = mod(temp_targ, 10)
       reversed = reversed * 10 + remainder
       temp_targ = temp_targ / 10
    enddo
    
    is_pal_res = (original == reversed)
    
  end function is_pal

  subroutine test_is_pal_and_main()
    implicit none
    logical :: result
    
    ! Test the is_pal function
    result = is_pal(12321)
    if (result) then
       write(*,*) "Test 1 (is_pal with 12321): Pass"
    else
       write(*,*) "Test 1 (is_pal with 12321): Fail"
    endif
    
    result = is_pal(12345)
    if (.not. result) then
       write(*,*) "Test 2 (is_pal with 12345): Pass"
    else
       write(*,*) "Test 2 (is_pal with 12345): Fail"
    endif
    
    ! Assuming the known largest palindrome product of two 3-digit numbers is 906609
    if (max_pal == 906609) then
       write(*,*) "Overall Program Logic Test: Pass"
    else
       write(*,*) "Overall Program Logic Test: Fail"
    endif
  end subroutine test_is_pal_and_main

end program main