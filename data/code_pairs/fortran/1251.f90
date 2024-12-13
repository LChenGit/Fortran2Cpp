module great_module
    implicit none
    character(len=10), allocatable :: relationships(:,:)
    integer :: num_relationships = 0

contains

    subroutine great(entity1, entity2)
        character(len=*), intent(in) :: entity1, entity2

        if (.not. allocated(relationships)) then
            allocate(relationships(2, 1))
        else
            allocate(relationships(2, num_relationships + 1), mold=relationships)
        end if

        num_relationships = num_relationships + 1
        relationships(1, num_relationships) = entity1
        relationships(2, num_relationships) = entity2
    end subroutine great

    subroutine print_relationships()
        integer :: i
        print *, 'Relationships:'
        do i = 1, num_relationships
            print *, trim(relationships(1, i)), '->', trim(relationships(2, i))
        end do
    end subroutine print_relationships

end module great_module