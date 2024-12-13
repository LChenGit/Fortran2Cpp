module ModExample2

  implicit none
  private
  public :: example_iroutine
  character(len=*), parameter :: NameMod = 'ModExample2'

contains

  subroutine example_iroutine(InputVar, OutputVar, InputOutputVar)

    ! Assuming ExampleParameter is a real number for demonstration purposes
    real, parameter :: ExampleParameter = 1.0

    real, intent(in) :: InputVar
    real, intent(out) :: OutputVar
    real, intent(inout) :: InputOutputVar

    character(len=*), parameter :: NameSub = NameMod//'::example_iroutine'

    write(*,*) NameSub, ': documented executable statements come here'
    write(*,*) NameSub, ': this part should not appear in the documentation'

    ! Example computation to demonstrate functionality
    OutputVar = InputVar * ExampleParameter * 2.0
    InputOutputVar = InputOutputVar * 3.0

  end subroutine example_iroutine

end module ModExample2