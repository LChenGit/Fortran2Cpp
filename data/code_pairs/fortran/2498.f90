module misc_mod
    implicit none
    integer, parameter :: mk = selected_real_kind(15, 307)
end module misc_mod

module servo_with_limits_data
    use misc_mod
    implicit none
    integer :: nblades, stepno, stuck_type
    real(mk) :: omega0, beta0, vmax, amax, theta_min, theta_max
    real(mk) :: time_runaway, time_stuck, stuck_angle
    real(mk) :: oldtime, theta_ref, yold(2,3), ynew(2,3)
    real(mk) :: oldarray2(100)
    real(mk) :: timestep
end module servo_with_limits_data

program test_servo_with_limits
    use servo_with_limits_data
    implicit none

    integer :: i

    ! Initialize module variables
    nblades = 4
    omega0 = 1.5
    yold(1,1) = 1.0
    ynew(2,3) = 1.0
    
    oldarray2(50) = 50.0

    ! Display some values to ensure the correctness
    print *, "nblades = ", nblades
    print *, "omega0 = ", omega0
    print *, "yold(1,1) = ", yold(1,1)
    print *, "ynew(2,3) = ", ynew(2,3)
    print *, "oldarray2(50) = ", oldarray2(50)

end program test_servo_with_limits