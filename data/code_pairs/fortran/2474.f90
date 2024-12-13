program test_fortran
  implicit none

  integer :: resc(3), tmp(3)
  integer :: me, boss, i
  integer, parameter :: num_images = 4  ! Assuming a total of 4 processes for this simulation
  integer :: image_index

  ! Simulating the this_image() and num_images() functionality for each possible "image"
  do image_index = 1, num_images
     me = image_index
     boss = 3

     ! Initialize resc based on the condition
     if (me == boss) then
        resc = 0
     else
        resc = -huge(0)
     endif

     ! Simulate the critical section and operations for both boss and non-boss "images"
     if (me /= boss) then
        ! Simulating interaction with the boss "process"
        tmp = resc
        tmp(1) = tmp(1) + 1
        tmp(2) = tmp(2) + 1
        ! Simulating sending the modified array back to the boss
        resc = tmp
     else
        ! Simulating the boss process updating its own array
        do i = 1, 100 * (num_images - 1)
           resc(1) = resc(1) - 1
           resc(3) = resc(3) + 1
        end do
     endif

     ! Printing the results for this simulation
     print *, "Image ", me, ":", resc
  end do

end program test_fortran