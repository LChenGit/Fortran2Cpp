module update_veloc_module
  implicit none
contains
  subroutine updateVelocElasticNewmark(old_velocity, acceleration, time, new_velocity)
    real, intent(in) :: old_velocity, acceleration, time
    real, intent(out) :: new_velocity
    new_velocity = old_velocity + acceleration * time
  end subroutine updateVelocElasticNewmark
end module update_veloc_module