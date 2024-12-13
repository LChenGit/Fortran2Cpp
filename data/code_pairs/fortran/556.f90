program test_gt_int
  implicit none

  ! Test cases
  call test_case(5, 3)
  call test_case(3, 5)
  call test_case(4, 4)

contains

  logical function gt_int(x, y)
    integer, intent(in) :: x
    integer, intent(in) :: y

    if (x > y) then
       gt_int = .true.
    else
       gt_int = .false.
    end if
  end function gt_int

  subroutine test_case(x, y)
    integer, intent(in) :: x
    integer, intent(in) :: y

    if (gt_int(x, y)) then
       write(*,*) x, '>', y, ': True'
    else
       write(*,*) x, '>', y, ': False'
    endif
  end subroutine test_case

end program test_gt_int