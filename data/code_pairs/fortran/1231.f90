subroutine xxcase(input, output, type)
    implicit none
    character(len=*), intent(in) :: input
    character(len=*), intent(out) :: output
    character(len=2), intent(in) :: type
    integer :: i, size

    size = len_trim(input)
    output = input

    if (type .eq. 'UC' .or. type .eq. 'uc') then
        do i = 1, size
            if (ichar(input(i:i)) >= ichar('a') .and. ichar(input(i:i)) <= ichar('z')) then
                output(i:i) = char(ichar(input(i:i)) - ichar('a') + ichar('A'))
            end if
        end do
    elseif (type .eq. 'LC' .or. type .eq. 'lc') then
        do i = 1, size
            if (ichar(input(i:i)) >= ichar('A') .and. ichar(input(i:i)) <= ichar('Z')) then
                output(i:i) = char(ichar(input(i:i)) - ichar('A') + ichar('a'))
            end if
        end do
    end if
end subroutine xxcase

program testXXCase
    implicit none
    character(len=100) :: output

    call xxcase('hello, world!', output, 'UC')
    print *, 'UC: ', output

    call xxcase('HELLO, WORLD!', output, 'LC')
    print *, 'LC: ', output

    call xxcase('Hello, World!', output, 'uc')
    print *, 'uc: ', output

    call xxcase('Hello, World!', output, 'lc')
    print *, 'lc: ', output
end program testXXCase