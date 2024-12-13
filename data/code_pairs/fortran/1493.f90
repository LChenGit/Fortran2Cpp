module foo_fixed
  contains
    subroutine bar12(a)
      integer, intent(inout) :: a
      a = 12
    end subroutine bar12
end module foo_fixed