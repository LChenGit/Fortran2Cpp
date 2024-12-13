program ft
    implicit none
    double precision :: t_m = -1.0d0  ! Example initialization; adapt as needed

    if (t_m <= 0.0d0) t_m = 1.0d0
    print *, "t_m:", t_m
end program ft