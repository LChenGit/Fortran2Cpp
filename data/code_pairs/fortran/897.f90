module test_module
  implicit none
  type :: t
    integer :: A
    real, allocatable :: B(:)
  end type t
contains
  subroutine class(z)
    class(t), intent(in) :: z(:)
    select type(z)
     type is(t)
      if (size (z) /= 10) call abort ()
      do i = 1, 10
        if (z(i)%a /= -i .or. size (z(i)%b) /= 4 &
            .or. any (z(i)%b /= [1*i,2*i,3*i,4*i])) then
            call abort()
        end if
      end do
    end select
  end subroutine class

  subroutine classExplicit(u, n)
    integer, intent(in) :: n
    class(t), intent(in) :: u(n)
    select type(u)
     type is(t)
      if (size (u) /= 10) call abort ()
      do i = 1, 10
        if (u(i)%a /= -i .or. size (u(i)%b) /= 4 &
            .or. any (u(i)%b /= [1*i,2*i,3*i,4*i])) then
            call abort()
        end if
      end do
    end select
  end subroutine classExplicit
end module test_module

program main_with_tests
  use test_module
  implicit none
  type(t), allocatable :: x(:)
  type(t) :: y(10)
  integer :: i

  ! Allocate and Initialize
  allocate(x(10))
  x = [(t(a=-i, B=[1*i,2*i,3*i,4*i]), i = 1, 10)]

  ! Copy x to y
  y = x

  ! Call class functions with x and y
  call class(x)
  call classExplicit(x, size(x))
  call class(y)
  call classExplicit(y, size(y))

  ! Running Tests
  write(*,*) 'Running Fortran Unit Tests...'
  ! Since the main functionality already performs checks, this serves as a basic test
  write(*,*) 'Fortran Unit Tests Completed Successfully.'
end program main_with_tests