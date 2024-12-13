PROGRAM GenerateKML
    IMPLICIT NONE

    INTEGER :: iunit = 10
    CHARACTER(LEN=20) :: filename = 'test_fortran.kml'
    
    ! Open file with a unit number and replace if it exists
    OPEN(UNIT=iunit, FILE=filename, STATUS='replace', ACTION='write')
    
    ! Write content to the file
    CALL WriteKMLHeader(iunit)
    CALL WritePlacemark(iunit, "Test Placemark", 10.0, 10.0, 1.0)
    CALL WriteKMLEnd(iunit)
    
    ! Close the file
    CLOSE(iunit)
    
END PROGRAM GenerateKML

SUBROUTINE WriteKMLHeader(iunit)
    INTEGER, INTENT(IN) :: iunit
    WRITE(iunit,*) '<?xml version="1.0" encoding="UTF-8"?>'
    WRITE(iunit,*) '<kml xmlns="http://www.opengis.net/kml/2.2">'
    WRITE(iunit,*) '<Document>'
END SUBROUTINE WriteKMLHeader

SUBROUTINE WritePlacemark(iunit, name, latitude, longitude, altitude)
    INTEGER, INTENT(IN) :: iunit
    CHARACTER(LEN=*), INTENT(IN) :: name
    REAL, INTENT(IN) :: latitude, longitude, altitude
    WRITE(iunit,*) '<Placemark>'
    WRITE(iunit,*) '<name>', name, '</name>'
    WRITE(iunit,*) '<Point>'
    WRITE(iunit,*) '<coordinates>', longitude, ',', latitude, ',', altitude, '</coordinates>'
    WRITE(iunit,*) '</Point>'
    WRITE(iunit,*) '</Placemark>'
END SUBROUTINE WritePlacemark

SUBROUTINE WriteKMLEnd(iunit)
    INTEGER, INTENT(IN) :: iunit
    WRITE(iunit,*) '</Document>'
    WRITE(iunit,*) '</kml>'
END SUBROUTINE WriteKMLEnd