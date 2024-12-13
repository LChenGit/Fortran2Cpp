! Define the subroutine
      subroutine xsetun (lun)
      implicit none
      integer lun, mesflg, lunit
      common /eh0001/ mesflg, lunit
      if (lun .gt. 0) lunit = lun
      return
      end

! Unit test program for the subroutine
      program testxsetun
      implicit none
      integer mesflg, lunit
      common /eh0001/ mesflg, lunit

      lunit = 0 ! Initialize lunit for testing
      
      call xsetun(-1)
      if (lunit .eq. 0) then
          print *, 'Test 1 passed.'
      else
          print *, 'Test 1 failed.'
      endif

      call xsetun(5)
      if (lunit .eq. 5) then
          print *, 'Test 2 passed.'
      else
          print *, 'Test 2 failed.'
      endif

      end program testxsetun