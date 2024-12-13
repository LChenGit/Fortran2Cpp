module node_module
  implicit none
  type :: Node
     integer :: data
     type(Node), pointer :: next => null()
  end type Node

contains

  function add_nodes(node1, node2) result(newNode)
    type(Node), intent(in) :: node1, node2
    type(Node) :: newNode

    newNode%data = node1%data + node2%data
    newNode%next => null()
  end function add_nodes

end module node_module