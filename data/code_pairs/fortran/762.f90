module my_subroutines
  implicit none
contains

  subroutine foo(array1, array2)
    integer, intent(inout) :: array1(:, :)
    real, intent(inout) :: array2(:, :, :)

    array1 = 5
    array1(1, 1) = 30

    array2 = 3.0
    array2(1, 1, 1) = 30.0
    array2(3, 3, 3) = 90.0
  end subroutine foo

end module my_subroutines