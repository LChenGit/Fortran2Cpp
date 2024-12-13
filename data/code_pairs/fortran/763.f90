! dat_node_mod.f90
module DAT_MOD
    implicit none
    type :: DAT
        integer :: NN
    contains
        procedure :: less_than => DAT_LT
    end type DAT
contains
    logical function DAT_LT(this, other)
        class(DAT), intent(in) :: this, other
        DAT_LT = this%NN < other%NN
    end function DAT_LT
end module DAT_MOD

module NODE_MOD
    use DAT_MOD
    implicit none
    type :: NODE
        integer :: KEY
        type(DAT), pointer :: PTR
    contains
        procedure :: less_than => NODE_LT
    end type NODE
contains
    logical function NODE_LT(this, other)
        class(NODE), intent(in) :: this, other
        if (this%KEY /= other%KEY) then
            NODE_LT = this%KEY < other%KEY
        else
            NODE_LT = this%PTR%NN < other%PTR%NN
        endif
    end function NODE_LT
end module NODE_MOD

program test_dat_node
    use DAT_MOD
    use NODE_MOD
    implicit none

    type(DAT), allocatable :: dat1, dat2
    type(NODE) :: node1, node2

    allocate(dat1)
    allocate(dat2)
    dat1%NN = 10
    dat2%NN = 20

    node1%KEY = 1
    node1%PTR => dat1
    node2%KEY = 2
    node2%PTR => dat2

    if (node1 < node2) then
        print *, "DAT Test Passed."
    else
        print *, "DAT Test Failed."
    endif

    if (node1 < node2) then
        print *, "NODE Test Passed."
    else
        print *, "NODE Test Failed."
    endif
end program test_dat_node