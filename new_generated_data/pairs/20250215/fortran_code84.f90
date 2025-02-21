program testcase
    integer :: ivar1
    character(len=8) :: cvar1
    character(len=1) :: cvar2
    logical :: lvar1
    real :: rvar1

    ! Initialize variables
    ivar1 = 3
    lvar1 = .true.

    ! First SELECT CASE block
    select case (ivar1)
    case (:-1)
        cvar1 = 'path'
    case (10/5 - 2)  ! 0
        ! No action
    case (1)
        ! No action
    case (2:3,5:7,9)
        ! No action
    case (10:)
        ! No action
    case default
        cvar1 = 'no path!'
        cvar2 = 'd'
    end select

    ! Second SELECT CASE block for logical variable
    select case (lvar1)
    case (.false.)
        ! No action
    case (.true.)
        ! No action
    end select

    ! Modify cvar1 for the third SELECT CASE
    cvar1 = 'hamster'
    select case (cvar1)
    case (:'cat')
        ! No action
    case ('dog':'ferret')
        ! No action
    case ('gerbil')
        ! No action
    case ('horse':)
        ! No action
    case default
        ! No action
    end select

    ! Unit tests
    if (cvar2 /= 'd') then
        write(*, *) "Test case 1 failed: cvar2 not 'd'"
        call exit(1)
    end if

    if (cvar1 /= 'hamster') then
        write(*, *) "Test case 2 failed: cvar1 not 'hamster'"
        call exit(1)
    end if

    if (ivar1 /= 3) then
        write(*, *) "Test case 3 failed: ivar1 not 3"
        call exit(1)
    end if

    if (lvar1 .neqv. .true.) then
        write(*, *) "Test case 4 failed: lvar1 not .true."
        call exit(1)
    end if

    if (rvar1 /= 0.0) then
        write(*, *) "Test case 5 failed: rvar1 not 0.0"
        call exit(1)
    end if

    write(*, *) "All tests passed."
    stop
end program testcase