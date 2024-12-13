program testProgram
    implicit none
    character, pointer :: ptr(:)
    character(8) :: a
    allocate(ptr(9))
    ptr = transfer('Sample#0'//achar(0), ptr)
    if (any(ptr .ne. ['S', 'a', 'm', 'p', 'l', 'e', '#', '0', achar(0)])) stop 1
    call test(a)
    if (a .ne. 'Sample#2') stop 2
contains
    subroutine test(a)
        character(len=*) :: a
        a = 'Sample#2'
    end subroutine test
end program testProgram