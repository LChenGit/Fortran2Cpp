program string_test
    character*8 c, b
    character a

    b = "HIFROMPGI"
    c = b(2:7)
    a = c(1:1)

    call test(c, a)
end program string_test

subroutine test(c, a)
    character*8 c
    character a

    ! Test cases
    if (c .eq. "IFROMP") then
        print *, "Test for c passed."
    else
        print *, "Test for c failed."
    endif

    if (a .eq. "I") then
        print *, "Test for a passed."
    else
        print *, "Test for a failed."
    endif
end subroutine test