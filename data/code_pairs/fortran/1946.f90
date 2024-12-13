module btn_module
contains
  subroutine btn(n, b)
    integer, intent(out) :: n
    logical, intent(in) :: b(:)
    integer :: i

    n = 0
    do i = size(b), 1, -1
      n = n * 2
      if (b(i)) n = n + 1
    end do
  end subroutine btn
end module btn_module

program test
  use btn_module
  implicit none
  integer :: result
  logical, dimension(3) :: test_case1 = [.true., .true., .true.]
  logical, dimension(4) :: test_case2 = [.true., .false., .true., .true.]

  call btn(result, test_case1)
  write(*,*) "Result for test case 1 (should be 7):", result

  call btn(result, test_case2)
  write(*,*) "Result for test case 2 (should be 13):", result
end program test