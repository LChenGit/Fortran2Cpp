module geohashmod
    implicit none
    integer, parameter :: sp = kind(1.0)
    integer, parameter :: i4 = kind(1)
contains
    integer(i4) function geohash(lon, lat)
        real(sp), intent(in) :: lon, lat
        real(sp), parameter :: scale = 120.0_sp
        real(sp), parameter :: offset = 0.5_sp
        integer(i4), parameter :: rowlen = nint(scale * 360.0_sp)
        integer(i4) :: i, j
        i = nint(offset + scale * (lon + 180.0_sp))
        j = nint(offset + scale * (lat + 90.0_sp))
        geohash = i + rowlen * (j - 1)
    end function geohash
end module