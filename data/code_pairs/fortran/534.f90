module io_m
  implicit none
contains

  subroutine open_file(filename, access, form, action, iu)
    character(len=*), intent(in) :: filename, access, form, action
    integer, intent(out) :: iu
    open(newunit=iu, file=filename, status='replace', action=action, form=form, access=access)
  end subroutine open_file

  subroutine close_file(iu)
    integer, intent(in) :: iu
    close(iu)
  end subroutine close_file

  subroutine iostat_update(ierr)
    integer, intent(in) :: ierr
    if (ierr /= 0) print *, "IO Error occurred."
  end subroutine iostat_update

end module io_m