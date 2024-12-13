module classify_mod
    implicit none
contains
    subroutine classifyNumber(number)
        integer, intent(in) :: number
        if (number > 0) then
            print *, 'Positive'
        else if (number < 0) then
            print *, 'Negative'
        else
            print *, 'Zero'
        end if
    end subroutine classifyNumber
end module classify_mod

program test_classify
    use classify_mod
    implicit none
    call classifyNumber(5)
    call classifyNumber(-3)
    call classifyNumber(0)
end program test_classify