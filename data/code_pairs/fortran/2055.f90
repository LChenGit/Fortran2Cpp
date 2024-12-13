! main.f90
program main
  use openacc
  implicit none

  integer n

  if (acc_get_num_devices(acc_device_nvidia) == 0) stop

  call acc_init(acc_device_nvidia)

  n = 0

  call acc_set_device_num(n, acc_device_nvidia)

  if (acc_get_device_num(acc_device_nvidia) /= 0) stop

  if (acc_get_num_devices(acc_device_nvidia) > 1) then
    n = 1
    call acc_set_device_num(n, acc_device_nvidia)
    if (acc_get_device_num(acc_device_nvidia) /= 1) stop
  endif

  call acc_shutdown(acc_device_nvidia)

end program