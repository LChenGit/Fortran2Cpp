module my_module
  implicit none
  real, target, save :: a1(3)
  real, target :: a2
  real, save :: a3
  real, target, save :: a4
contains
  subroutine objectpointers(j)
    integer, intent(in) :: j
    real, allocatable, target, save :: x1
    real, codimension[*], target, save :: x2
    real, save :: x3
    real, target :: x4
    real, target, save :: x5(10)
    real, pointer :: p1 => x1
    real, pointer :: p2 => x2
    real, pointer :: p3 => x3
    real, pointer :: p4 => x4
    real, pointer :: p5 => x5(j)
    real, pointer :: p6 => x5
  end subroutine

  subroutine dataobjects(j)
    integer, intent(in) :: j
    real, parameter :: x1(*) = [1., 2.]
    real, parameter :: x2(*,*) = reshape([1., 2., 3., 4.], [2,2])
    real, parameter :: x3(j) = [1., 2.]
    real :: x4(j) = [1., 2.]
    real :: x5(2,2) = reshape([1., 2., 3., 4.], [2,2])
    real :: x6(2,2) = 5.
    real :: x7 = 1.
    real :: x8(2,2) = reshape([1., 2., 3., 4.], [2,2])
    real :: x9(3) = [1., 2., 3.]
    real :: x10(2,3) = reshape([(real(k), k=1,6)], [2,3])
  end subroutine

  subroutine components
    type :: t1
      real :: x1(2) = [1., 2.]
    end type t1

    type :: t2
      integer, len :: kind
      integer, len :: len
      real :: x1(2) = [1., 2.]
      real :: x2(kind) = [1., 2., 3.]
      real :: x3(len) = [1., 2., 3.]
      real, pointer :: p1(:) => a1
      real, pointer :: p2 => a2
      real, pointer :: p3 => a3
      real, pointer :: p4 => a1
      real, pointer :: p5(:) => a4
    end type t2

    type(t2), parameter :: o1 = t2(3,3,[1.,2.,3.],[1.,2.,3.],[1.,2.,3.])
    type(t2), parameter :: o2 = t2(2,2,[1.,2.],[1.,2.],[1.,2.])
  end subroutine components
end module my_module

program test_fortran_code
  use my_module
  implicit none

  call objectpointers(5)
  call dataobjects(2)
  call components()
  print *, "All tests passed."
  
end program test_fortran_code