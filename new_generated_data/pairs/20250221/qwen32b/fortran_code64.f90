program main
    implicit none
    integer, dimension(2,3) :: array, brray
    integer :: i, j

    ! Function interface declaration
    interface
        function Function_Test(input)
            integer, dimension(:), intent(in) :: input
            integer, dimension(size(input)) :: Function_Test
        end function Function_Test
    end interface

    ! Initialize Array with the given values
    array = reshape( [1,4,2,5,3,6], [2,3] )
    brray = 0

    ! Apply Function_Test to the first row of array and assign to brray's first row
    brray(1,:) = Function_Test( array(1,:) )

    ! Apply Function_Test again to update the first row of array
    array(1,:) = Function_Test( array(1,:) )

    ! Print the results
    print *, "Array after update:"
    do i = 1, 2
        do j = 1, 3
            print '(I4)', array(i,j)
        end do
    end do

    print *, "Brray after function call:"
    do i = 1, 2
        do j = 1, 3
            print '(I4)', brray(i,j)
        end do
    end do

end program main

function Function_Test(input)
    integer, dimension(:), intent(in) :: input
    integer, dimension(size(input)) :: Function_Test
    integer :: i

    do i = 1, size(input)
        Function_Test(i) = input(i) + 10
    end do
end function Function_Test