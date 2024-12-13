module elements
  implicit none
  type :: element_type
     type(ele_numbering_type), pointer :: numbering
  end type element_type

  type :: ele_numbering_type
     integer, dimension(:,:), allocatable :: number2count
  end type ele_numbering_type
end module elements