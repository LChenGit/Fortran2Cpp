module NeighborFinder
contains
    subroutine FindElemEdgeNeighbor(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
        integer, intent(in) :: ElemConnectivity(:,:)
        integer, intent(in) :: ElemId1, ElemEdge1
        logical, intent(out) :: bflag
        integer, intent(out) :: ElemId2, ElemEdge2

        bflag = .false.
        ElemId2 = ElemId1 + 1
        ElemEdge2 = ElemEdge1 + 1
    end subroutine FindElemEdgeNeighbor

    subroutine FindElemEdgeNeighbor2(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
        integer, intent(in) :: ElemConnectivity(:,:)
        integer, intent(in) :: ElemId1, ElemEdge1
        logical, intent(out) :: bflag
        integer, intent(out) :: ElemId2, ElemEdge2

        bflag = .true.
        ElemId2 = ElemId1 - 1
        ElemEdge2 = ElemEdge1 - 1
    end subroutine FindElemEdgeNeighbor2
end module NeighborFinder