program test
      implicit none
      integer :: a(10), i

      write(*,*) 'This is a test.'
      call sub(a,10)
      do i=1,10
         if (a(i) .ne. i) then
            write(*,*) 'Test failed at index:', i
            stop
         endif
      end do
      write(*,*) 'Test passed.'
      write(*,*) (a(i), i=1,10)
      stop
      end

      subroutine sub(a,n)
      implicit none
      integer, dimension(n) :: a
      integer :: i

      do i = 1, n 
        a(i) = i
      end do
      return
      end