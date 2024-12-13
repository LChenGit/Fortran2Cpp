module getbuf_mod
  implicit none
contains
  subroutine GETBUF(BUF1,BUF2,NPIX,NRAST)
    integer :: NPIX, NRAST, I
    real, dimension(NPIX*NRAST) :: BUF1, BUF2

    do I=1,NPIX*NRAST
      BUF2(I) = BUF1(I)
    end do
  end subroutine GETBUF
end module getbuf_mod