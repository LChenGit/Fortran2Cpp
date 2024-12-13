! Assuming xmp_lib.h or equivalent module declarations for xmp_num_nodes and xmp_node_num
module mock_xmp
    implicit none
contains
    function xmp_num_nodes() result(num_nodes)
        integer :: num_nodes
        num_nodes = 4  ! Example value
    end function xmp_num_nodes

    function xmp_node_num() result(node_num)
        integer :: node_num
        node_num = 1  ! Example value, could vary
    end function xmp_node_num
end module mock_xmp

program main
    use mock_xmp
    integer :: procs, id
    integer :: mask1, val1
    integer :: mask2, val2
    logical :: l1, l2
    character(len=2) :: result
    integer :: i

    if(xmp_num_nodes() > 31) then
        print *, 'You have to run this program by less than 32 nodes.'
        stop
    endif

    procs = xmp_num_nodes()
    id = xmp_node_num() - 1
    result = 'OK'

    do i = 0, 2**procs - 1, 2
        mask1 = ishft(1, id)
        val1 = iand(i, mask1)
        l1 = (val1 /= 0)

        mask2 = ishft(1, id)
        val2 = iand(i+1, mask2)
        l2 = (val2 /= 0)

        if (l1) result = 'NG'
        if (i+1 == 2**procs - 1) then
            if (.not. l2) result = 'NG'
        else
            if (l2) result = 'NG'
        endif
    end do

    print *, xmp_node_num(), 'test ', result
end program main