module tao_random_numbers
  integer, dimension(10) :: s_buffer
  integer :: s_last = size(s_buffer)
end module tao_random_numbers

module linalg
  contains
  function diag(a) result(d)
    real, dimension(:,:), intent(in) :: a
    real, dimension(size(a,1)) :: d
    integer :: i
    do i = 1, size(a,1)
       d(i) = a(i,i)
    end do
  end function diag
end module linalg

program test_program
  use tao_random_numbers
  use linalg
  implicit none
  
  real :: x(2, 2) = reshape([1.,2.,3.,4.], shape=[2,2])
  real, dimension(2) :: diag_x

  print *, 's_last:', s_last
  diag_x = diag(x)
  print *, 'Diagonal elements of x:', diag_x
end program test_program