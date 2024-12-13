module mod_lbmodel
    implicit none
    type :: velType
        real :: coo(3)
    end type velType

    type :: lbmodelType
        type(velType), allocatable :: vel(:)
    end type lbmodelType

    type(lbmodelType) :: lbm
end module mod_lbmodel