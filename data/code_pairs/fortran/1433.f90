! fluid_model_toy.f90
module fluid_model_toy
  implicit none

  real :: density = 0.0
  real :: velocity = 0.0
  real :: pressure = 0.0

contains

  subroutine initialize()
    density = 1.0
    velocity = 2.0
    pressure = 101.3
  end subroutine initialize

  subroutine calculate()
    pressure = density * velocity * 2.0
  end subroutine calculate

  subroutine deleteModel()
    density = 0.0
    velocity = 0.0
    pressure = 0.0
  end subroutine deleteModel

end module fluid_model_toy