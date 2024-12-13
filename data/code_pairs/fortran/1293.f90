program main
  use openacc
  implicit none

  integer :: n, num_devices

  num_devices = acc_get_num_devices(acc_device_nvidia)

  if (num_devices == 0) then
     print *, "No NVIDIA devices available - Exiting"
     stop
  end if

  call acc_init(acc_device_nvidia)

  n = 0
  call acc_set_device_num(n, acc_device_nvidia)

  if (acc_get_device_num(acc_device_nvidia) /= 0) then
     print *, "Device not set correctly - Exiting"
     stop
  end if

  if (num_devices > 1) then
     n = 1
     call acc_set_device_num(n, acc_device_nvidia)
     if (acc_get_device_num(acc_device_nvidia) /= 1) then
        print *, "Second device not set correctly - Exiting"
        stop
     end if
  end if

  call acc_shutdown(acc_device_nvidia)

end program