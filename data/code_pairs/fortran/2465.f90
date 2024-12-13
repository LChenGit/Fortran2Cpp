! prog.f90
program prog
    dimension vals(4)
    common /val_comm/ vals

    call compute_vals

    write(6, '(4f5.2)') (vals(i), i=1,4)
end program prog

subroutine compute_vals
    dimension vals(4)
    common /val_comm/ vals

    vals(1) = 1.2
    vals(2) = vals(1)**2
    vals(3) = 2**vals(2)
    vals(4) = vals(2)**vals(3)
end subroutine compute_vals