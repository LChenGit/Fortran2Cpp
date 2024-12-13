module mod_arrays

    implicit none

    private
    public :: reverse
    public :: average
    public :: std
    public :: moving_average
    public :: moving_std

contains

    pure function reverse(x)
        real, intent(in) :: x(:)
        real :: reverse(size(x))

        reverse = x(size(x):1:-1)
    end function reverse

    pure real function average(x)
        real, intent(in) :: x(:)

        average = sum(x) / size(x)
    end function average

    pure real function std(x)
        real, intent(in) :: x(:)

        std = sqrt(sum((x - average(x))**2) / size(x))
    end function std

    pure function moving_average(x, window_size) result(ma)
        real, intent(in) :: x(:)
        integer, intent(in) :: window_size
        real :: ma(size(x))
        integer :: i, lower_bound

        do i = 1, size(x)
            lower_bound = max(i - window_size + 1, 1)
            ma(i) = average(x(lower_bound:i))
        end do
    end function moving_average

    pure function moving_std(x, window_size) result(ms)
        real, intent(in) :: x(:)
        integer, intent(in) :: window_size
        real :: ms(size(x))
        integer :: i, lower_bound

        do i = 1, size(x)
            lower_bound = max(i - window_size + 1, 1)
            ms(i) = std(x(lower_bound:i))
        end do
    end function moving_std

end module mod_arrays