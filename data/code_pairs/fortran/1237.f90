module data_structures
    implicit none
    type Time_type
        integer :: time
    end type Time_type

    type config
        type(Time_type) :: first_time
        type(Time_type) :: last_time
        type(Time_type) :: training_start
        type(Time_type) :: training_stop
        type(Time_type) :: transform_start
        type(Time_type) :: transform_stop
    end type config

    type base_data_type
        type(Time_type), dimension(:), allocatable :: times
        type(Time_type) :: first_time
        type(Time_type) :: last_time
        type(Time_type) :: training_start
        type(Time_type) :: training_stop
        type(Time_type) :: transform_start
        type(Time_type) :: transform_stop
    end type base_data_type
end module data_structures

module time_util
    use data_structures
    implicit none
    
contains
    subroutine setup_time_indices(input, options)
        type(base_data_type), intent(inout) :: input
        type(config), intent(in) :: options

        input%first_time%time = find_nearest_time(input%times, options%first_time%time)
        input%last_time%time = find_nearest_time(input%times, options%last_time%time)
        input%training_start%time = find_nearest_time(input%times, options%training_start%time)
        input%training_stop%time = find_nearest_time(input%times, options%training_stop%time)
        input%transform_start%time = find_nearest_time(input%times, options%transform_start%time)
        input%transform_stop%time = find_nearest_time(input%times, options%transform_stop%time)
    end subroutine setup_time_indices

    function find_nearest_time(time_list, match_time) result(nearest_time)
        type(Time_type), dimension(:), intent(in) :: time_list
        integer, intent(in) :: match_time
        integer :: nearest_time, i, diff, minDiff
        nearest_time = 1
        minDiff = abs(time_list(1)%time - match_time)
        do i = 2, size(time_list)
            diff = abs(time_list(i)%time - match_time)
            if (diff < minDiff) then
                nearest_time = i
                minDiff = diff
            endif
        end do
        nearest_time = time_list(nearest_time)%time
    end function find_nearest_time
end module time_util