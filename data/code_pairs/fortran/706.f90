module vector_class
    implicit none
    private

    type :: vector
        integer :: index_ = 0
        integer :: length_real_ = 0
        integer, allocatable :: nodes_(:)
    end type vector

    public :: vector, set_this, delete_this, add_with_sort_this

contains

    subroutine set_this(this, index)
        type(vector), intent(inout) :: this
        integer, intent(in) :: index
        this%index_ = index
    end subroutine set_this

    subroutine delete_this(this)
        type(vector), intent(inout) :: this
        if (allocated(this%nodes_)) then
            deallocate(this%nodes_)
            this%length_real_ = 0
        endif
    end subroutine delete_this

    subroutine add_with_sort_this(this, node0)
        type(vector), intent(inout) :: this
        integer, intent(in) :: node0
        integer :: i, j
        if (this%index_ > node0) return
        if (this%length_real_ == 0) then
            allocate(this%nodes_(1))
            this%nodes_(1) = node0
            this%length_real_ = 1
        else
            this%length_real_ = this%length_real_ + 1
            if (.not. allocated(this%nodes_)) then
                allocate(this%nodes_(this%length_real_))
            else
                this%nodes_ = [this%nodes_, 0] ! Increase size by 1
            endif
            do i = this%length_real_ - 1, 1, -1
                if (node0 < this%nodes_(i)) then
                    this%nodes_(i+1) = this%nodes_(i)
                else
                    exit
                endif
            end do
            this%nodes_(i+1) = node0
        endif
    end subroutine add_with_sort_this

end module vector_class

program test_vector
    use vector_class
    implicit none

    type(vector) :: vec

    call set_this(vec, 10)
    call add_with_sort_this(vec, 5)
    call add_with_sort_this(vec, 3)
    call add_with_sort_this(vec, 7)

    print *, "Elements after adding: ", vec%nodes_(1:vec%length_real_)

    call delete_this(vec)
    print *, "Elements after deleting (should be empty):", vec%length_real_
end program test_vector