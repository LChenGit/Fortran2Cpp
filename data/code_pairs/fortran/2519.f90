! main.f90
program main
implicit none

integer, parameter :: ip1 = 42
integer, parameter :: ip2 = transfer(transfer(ip1, .true.), 0)
integer :: i, ai(4)
logical :: b

if (ip2 .ne. ip1) call abort ()

i = transfer(transfer(ip1, .true.), 0)
if (i .ne. ip1) call abort ()

i = 42
i = transfer(transfer(i, .true.), 0)
if (i .ne. ip1) call abort ()

b = transfer(transfer(.true., 3.1415), .true.)
if (.not.b) call abort ()

b = transfer(transfer(.false., 3.1415), .true.)
if (b) call abort ()

i = 0
b = transfer(i, .true.)

ai = (/ 42, 42, 42, 42 /)
ai = transfer (transfer (ai, .false., 4), ai)
if (any(ai .ne. 42)) call abort

ai = transfer (transfer ((/ 42, 42, 42, 42 /), &
&                          (/ .false., .false., .false., .false. /)), ai)
if (any(ai .ne. 42)) call abort

print *, 'Fortran test passed.'
end program main