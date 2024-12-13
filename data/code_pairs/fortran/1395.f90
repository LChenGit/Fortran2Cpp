subroutine srcom (rsav, isav, job)
      implicit none
      integer, intent(inout) :: isav(*), job
      double precision, intent(inout) :: rsav(*)
      integer ieh(2), ils(39)
      double precision rls(218)
      integer i, lenils, lenrls
      parameter (lenrls=218, lenils=39)
      common /ls0001/ rls, ils
      common /eh0001/ ieh

      if (job .eq. 2) then
          do i = 1,lenrls
              rls(i) = rsav(i)
          end do
          do i = 1,lenils
              ils(i) = isav(i)
          end do
          ieh(1) = isav(lenils+1)
          ieh(2) = isav(lenils+2)
      else
          do i = 1,lenrls
              rsav(i) = rls(i)
          end do
          do i = 1,lenils
              isav(i) = ils(i)
          end do
          isav(lenils+1) = ieh(1)
          isav(lenils+2) = ieh(2)
      end if
      return
      end

      program test_srcom
      implicit none
      integer :: i
      integer, parameter :: lenrls=218, lenils=39
      double precision :: rsav(lenrls)
      integer :: isav(lenils+2)
      integer :: job

      ! Initialize test data for srcom subroutine
      do i = 1, lenrls
          rsav(i) = i * 0.5
      end do
      do i = 1, lenils+2
          isav(i) = -i
      end do

      ! Example test case: job = 1
      job = 1
      call srcom(rsav, isav, job)
      ! Add checks here to verify the content of rsav and isav arrays
      print *, 'Test case for job=1 completed, check the array values manually.'

      end program test_srcom