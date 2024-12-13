program test_sub
  implicit none

contains

  subroutine sub(l2, m)
    implicit none
    integer, intent(in) :: l2
    integer, intent(out) :: m
    m = 1
    if (l2 >= 1 .and. l2 <= 4) m = l2
  end subroutine sub

  subroutine hoge(l1, m)
    implicit none
    integer, intent(in) :: l1
    integer, intent(out) :: m
    m = 1
    if (l1 >= 1 .and. l1 <= 4) m = l1
  end subroutine hoge

end program test_sub