program main
    implicit none
    integer, parameter :: s4 = selected_int_kind(8)
    integer, parameter :: s8 = selected_int_kind(10)
    integer, parameter :: k4 = kind(1)
    integer, parameter :: k8 = kind(1_8)
    integer, parameter :: r8 = kind(1.0D0)
    
    if (kind(0_s4) /= 4) then
        print *, "invalid s4"
    end if
    if (kind(0_s8) /= 8) then
        print *, "invalid s8"
    end if
    if (kind(0_k4) /= 4) then
        print *, "invalid k4"
    end if
    if (kind(0_k8) /= 8) then
        print *, "invalid k8"
    end if
    if (kind(0.0_r8) /= 8) then
        print *, "invalid r8"
    end if
end program main