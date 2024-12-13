program test_writeboun
  implicit none

  integer, parameter :: nboun = 3
  integer :: nodeboun(nboun) = (/1, 2, 3/)
  integer :: ndirboun(nboun) = (/100, 200, 300/)
  real*8 :: xboun(nboun) = (/1.234, 2.345, 3.456/)
  character(len=1) :: typeboun(nboun) = (/'A', 'B', 'C'/)

  call writeboun(nodeboun, ndirboun, xboun, typeboun, nboun)

contains

  subroutine writeboun(nodeboun, ndirboun, xboun, typeboun, nboun)
    implicit none
    integer, intent(in) :: nodeboun(*), ndirboun(*), nboun
    real*8, intent(in) :: xboun(*)
    character(len=1), intent(in) :: typeboun(*)
    integer :: i

    write(*,*)
    write(*,'("SPC ")') 
    do i = 1, nboun
       write(*,'(i5,1x,i10,1x,i5,1x,e11.4,1x,a1)') i, nodeboun(i), ndirboun(i), xboun(i), typeboun(i)
    end do
  end subroutine writeboun

end program test_writeboun