module s3_module
  implicit none
contains
  subroutine s3(n, z, y)
    integer, intent(in) :: n
    real, intent(out) :: z(:)
    real, intent(in) :: y(:)

    integer :: i
    do i = 1, n
       z(i) = y(i)  ! Copy operation
    end do
  end subroutine s3
end module s3_module