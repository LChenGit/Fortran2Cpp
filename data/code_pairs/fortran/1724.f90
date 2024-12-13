module mphys_interface

  implicit none

contains

  subroutine mphys_column(scheme_id)
    integer, intent(in) :: scheme_id

    select case (scheme_id)
    case (1) ! improcess_thompson09
       call mphys_thompson09_interface
    case (2) ! improcess_thompson07
       call mphys_thompson07_interface
    case (3) ! improcess_morr_two_moment
       call mphys_morrison_interface
    end select
  end subroutine mphys_column

  subroutine mphys_thompson09_interface
    print *, "Thompson 09 interface called"
  end subroutine mphys_thompson09_interface

  subroutine mphys_thompson07_interface
    print *, "Thompson 07 interface called"
  end subroutine mphys_thompson07_interface

  subroutine mphys_morrison_interface
    print *, "Morrison interface called"
  end subroutine mphys_morrison_interface

end module mphys_interface