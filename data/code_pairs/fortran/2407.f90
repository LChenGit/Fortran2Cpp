module gridQ_module
    implicit none
    ! Declare the variables
    integer :: nQ2g
    integer :: inter_degreeQ
    character(len=20) :: InQGrid
contains
    subroutine SetQGridParameters(npQ, degQ)
        implicit none
        integer, intent(in) :: npQ, degQ

        nQ2g = npQ
        inter_degreeQ = degQ
        InQGrid = "done"
    end subroutine SetQGridParameters
end module gridQ_module