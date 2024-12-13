module clock_m
    implicit none
    private
    public :: clock_t

    type :: clock_t
        real :: start_time
        real :: stop_time
        real :: time
    contains
        procedure :: start => start_clock
        procedure :: stop => stop_clock
    end type clock_t

contains
    subroutine start_clock(this)
        class(clock_t), intent(inout) :: this
        integer :: count_rate, count_max

        call system_clock(count_max=count_max, count_rate=count_rate)
        call system_clock(this%start_time)
        this%start_time = this%start_time / real(count_rate)
    end subroutine start_clock

    subroutine stop_clock(this)
        class(clock_t), intent(inout) :: this
        integer :: count_rate, count_max

        call system_clock(count_max=count_max, count_rate=count_rate)
        call system_clock(this%stop_time)
        this%stop_time = this%stop_time / real(count_rate)
        this%time = this%stop_time - this%start_time
    end subroutine stop_clock

end module clock_m