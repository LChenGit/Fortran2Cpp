subroutine networkinum(ipkon, inum, kon, lakon, ne, itg, ntg, network)
  implicit none

  integer, intent(in) :: ipkon(*), kon(*), ne, itg(*), ntg, network
  integer, intent(inout) :: inum(*)
  character(len=8), intent(in) :: lakon(*)
  
  integer :: i, indexe, node1, node2, node3
  
  do i = 1, ntg
     if (inum(itg(i)) > 0) inum(itg(i)) = -inum(itg(i))
  end do

  do i = 1, ne
     if (ipkon(i) < 0) cycle
     if ((lakon(i)(1:1) /= 'D') .and. ((lakon(i)(1:1) /= 'D') .or. (network /= 1))) cycle
     
     indexe = ipkon(i)
     if (kon(indexe+1) /= 0) then
        node1 = kon(indexe+1)
        if (inum(node1) > 0) inum(node1) = -inum(node1)
     end if
     node2 = kon(indexe+2)
     if (inum(node2) > 0) inum(node2) = -inum(node2)
     if (kon(indexe+3) /= 0) then
        node3 = kon(indexe+3)
        if (inum(node3) > 0) inum(node3) = -inum(node3)
     end if
  end do
end subroutine