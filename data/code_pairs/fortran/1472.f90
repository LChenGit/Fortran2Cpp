module matsize_checks
  implicit none
contains

  subroutine check_matsize_n(nsize1, nsize2, matrix, matname, subname)
    integer, intent(in) :: nsize1, nsize2
    integer, intent(in) :: matrix(:,:)
    character(len=*), intent(in) :: matname, subname
    if (size(matrix, 1) /= nsize1 .or. size(matrix, 2) /= nsize2) then
      print *, "Error in ", trim(subname), ": Matrix ", trim(matname), " has incorrect size."
    else
      print *, "Matrix ", trim(matname), " checked successfully in ", trim(subname), "."
    end if
  end subroutine check_matsize_n

  subroutine check_matsize_r(nsize1, nsize2, matrix, matname, subname)
    integer, intent(in) :: nsize1, nsize2
    real, intent(in) :: matrix(:,:)
    character(len=*), intent(in) :: matname, subname
    if (size(matrix, 1) /= nsize1 .or. size(matrix, 2) /= nsize2) then
      print *, "Error in ", trim(subname), ": Matrix ", trim(matname), " has incorrect size."
    else
      print *, "Matrix ", trim(matname), " checked successfully in ", trim(subname), "."
    end if
  end subroutine check_matsize_r

end module matsize_checks