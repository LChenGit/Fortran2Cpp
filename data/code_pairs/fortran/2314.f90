module check_module
    implicit none

contains

    logical function check_is_larger(i)
        integer, intent(in) :: i
        integer, save :: last_i = 0
        logical :: is_larger

        if (i == 1) then
            last_i = 0
        endif

        is_larger = (i >= last_i) .and. ((i - last_i) <= 1)
        last_i = i

        check_is_larger = is_larger
    end function check_is_larger

end module check_module

program test_do_collapse
    use check_module
    implicit none

    ! Test check_is_larger function
    print *, 'Testing check_is_larger function'
    print *, 'check_is_larger(1):', check_is_larger(1)
    print *, 'check_is_larger(2):', check_is_larger(2)
    print *, 'check_is_larger(4):', check_is_larger(4)

    ! Placeholder for do_collapse testing
    print *, 'Testing do_collapse function (Placeholder)'

end program test_do_collapse