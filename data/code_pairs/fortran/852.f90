module test1
contains
  subroutine valid (lhs,rhs)
    integer, intent(out) ::  lhs
    integer, intent(in) :: rhs(:)
    lhs = rhs(1) 
  end subroutine valid

  subroutine valid2 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs(:,:)
    lhs(:) = rhs(:,1) 
  end subroutine valid2
end module test1

module test2
contains
  subroutine invalid (lhs,rhs)
    integer, intent(out) ::  lhs
    integer, intent(in) :: rhs
    lhs = rhs
  end subroutine invalid
end module test2

module test3
contains
  subroutine invalid2 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs
    lhs(:) = rhs
  end subroutine invalid2
end module test3

module test4
contains
  subroutine invalid3 (lhs,rhs)
    integer, intent(out) ::  lhs(:)
    integer, intent(in) :: rhs(:)
    lhs(:) = rhs(:)
  end subroutine invalid3
end module test4