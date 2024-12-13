program test_select_case
  implicit none

  call testCase(1)
  call testCase(2)
  call testCase(3) ! This will test a value that doesn't match any of the cases.

contains

  subroutine testCase(nn)
    integer, intent(in) :: nn
    select case(nn)
    case(1)
      write(*,*) "case1"
    case(2)
      write(*,*) "case2"
    case default
      ! For values not matching any case, no output is produced, 
      ! aligning with the behavior of the original snippet.
    end select
  end subroutine testCase

end program test_select_case