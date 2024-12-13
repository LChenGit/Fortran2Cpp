program testS
    implicit none

    integer, dimension(3) :: intArray = [1, 2, 3]
    real, dimension(2) :: realArray = [1.1, 2.2]
    integer :: singleInt = 5

    call s(intArray, realArray, singleInt)

contains

    subroutine s(arg1, arg2, arg3)
        integer, dimension(:), intent(in) :: arg1
        real, dimension(:), intent(in) :: arg2
        integer, intent(in) :: arg3

        print *, "s_intArray called with integers:", arg1
        print *, "s_realArray called with reals:", arg2
        print *, "s_singleInt called with single integer:", arg3
    end subroutine s

end program testS