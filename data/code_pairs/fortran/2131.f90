module utils
    implicit none

    integer, parameter :: sp = selected_real_kind(6, 37)
    integer, parameter :: dp = selected_real_kind(15, 307)
    integer, parameter :: qp = selected_real_kind(33, 4931)
    integer, parameter :: log_unit = 99

contains
    subroutine log_init(filename)
        character(len=*) :: filename
        open(log_unit, file=trim(filename), status='unknown')
    end subroutine log_init

    subroutine log_warn(message)
        character(len=*) :: message
        write(log_unit, '(" ---- WARNING: ", A)') message
    end subroutine log_warn

    subroutine log_error(message)
        character(len=*) :: message
        write(log_unit, '(" **** ERROR: ", A)') message
    end subroutine log_error

    subroutine log_note(message)
        character(len=*) :: message
        write(log_unit, '(" NOTE: ", A)') message
    end subroutine log_note

    subroutine log_close()
        close(log_unit)
    end subroutine log_close

end module utils