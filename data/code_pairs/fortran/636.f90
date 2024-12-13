module rrsw_kg18
  implicit none
  real, parameter :: pi = 3.14159
  real, dimension(1:5) :: array1
  real, dimension(3) :: array2

contains
  subroutine computeSomething()
    array1(1) = pi
    array2(3) = 2.0 * pi
    ! More code here
  end subroutine computeSomething
end module rrsw_kg18