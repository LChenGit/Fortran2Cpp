program boom
    implicit none
    integer :: exitStatus, cmdStatus
    character(len=256) :: cmdMessage
    character(len=:), allocatable :: command

    ! Test 1: Command expected to succeed
    command = 'echo Hello'
    call executeCommandLine(command, exitStatus, cmdStatus, cmdMessage)
    if (cmdStatus /= 0) then
        print *, "Test 1 Failed."
    else
        print *, "Test 1 Passed."
    endif

    ! Test 2: Command expected to fail (nonexistent command)
    command = 'false'
    call executeCommandLine(command, exitStatus, cmdStatus, cmdMessage)
    if (cmdStatus == 0) then
        print *, "Test 2 Failed."
    else
        print *, "Test 2 Passed."
    endif
end program boom

subroutine executeCommandLine(command, exitStatus, cmdStatus, cmdMessage)
    character(len=*), intent(in) :: command
    integer, intent(out) :: exitStatus, cmdStatus
    character(len=256), intent(out) :: cmdMessage

    ! This is a placeholder for the command execution logic
    ! Assuming cmdStatus = 0 for success and non-zero for errors
    ! and exitStatus mirrors the system's behavior
    ! The actual system call and message handling is platform-dependent and not directly shown here

    exitStatus = 0
    cmdStatus = 0
    cmdMessage = "Success"
end subroutine executeCommandLine