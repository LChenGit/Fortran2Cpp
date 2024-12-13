module bind_c_array_params
    use, intrinsic :: iso_c_binding
    implicit none

contains
    subroutine sub0(assumed_array, n) bind(c)
        integer(c_int), dimension(*), intent(inout) :: assumed_array
        integer(c_int), value :: n
        integer :: i
        do i = 1, n
            assumed_array(i) = assumed_array(i) + 1
        end do
    end subroutine sub0

    subroutine sub1(deferred_array, n) bind(c)
        integer(c_int), dimension(:), intent(inout) :: deferred_array
        integer(c_int), value :: n
        integer :: i
        do i = 1, n
            deferred_array(i) = deferred_array(i) + 1
        end do
    end subroutine sub1
end module bind_c_array_params