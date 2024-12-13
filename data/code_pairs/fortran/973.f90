module nonlin_solve_line_search
    implicit none

    type :: line_search
        ! Dummy type for example.
    end type line_search

    type :: line_search_solver
        class(line_search), allocatable :: m_lineSearch
        logical :: m_useLineSearch = .false.
    contains
        procedure :: set_line_search
        procedure :: get_line_search
        procedure :: set_default
        procedure :: is_line_search_defined
        procedure :: get_use_search
        procedure :: set_use_search
    end type line_search_solver

contains

    subroutine set_line_search(this, ls)
        class(line_search_solver), intent(inout) :: this
        class(line_search), intent(in) :: ls
        if (allocated(this%m_lineSearch)) deallocate(this%m_lineSearch)
        allocate(this%m_lineSearch, source = ls)
    end subroutine set_line_search

    subroutine get_line_search(this, ls)
        class(line_search_solver), intent(in) :: this
        class(line_search), allocatable, intent(out) :: ls
        if (allocated(this%m_lineSearch)) then
            allocate(ls, source = this%m_lineSearch)
        endif
    end subroutine get_line_search

    subroutine set_default(this)
        class(line_search_solver), intent(inout) :: this
        type(line_search) :: ls
        call this%set_line_search(ls)
    end subroutine set_default

    function is_line_search_defined(this) result(res)
        class(line_search_solver), intent(in) :: this
        logical :: res
        res = allocated(this%m_lineSearch)
    end function is_line_search_defined

    function get_use_search(this) result(res)
        class(line_search_solver), intent(in) :: this
        logical :: res
        res = this%m_useLineSearch
    end function get_use_search

    subroutine set_use_search(this, val)
        class(line_search_solver), intent(inout) :: this
        logical, intent(in) :: val
        this%m_useLineSearch = val
    end subroutine set_use_search

end module nonlin_solve_line_search