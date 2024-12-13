subroutine write_latlong_data(lat, longitude)
    implicit none
    double precision, dimension(2) :: lat, longitude

    open(unit=10, file='latlong.dat')
    write(10, '(4E24.16)') lat(1), lat(2), longitude(1), longitude(2)
    close(10)
end subroutine write_latlong_data