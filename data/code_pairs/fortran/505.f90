! Fortran code to write and then read integers 1 to 10 to/from a file.
Program FortranFileIO
    Implicit None
    Integer :: i
    Integer, Dimension(10) :: data
    Integer :: readData(10)

    ! Initialize some data to write
    Do i = 1, 10
        data(i) = i
    End Do

    ! Write data to a file
    Call write_data_to_file('example.dat', data)

    ! Read data from the file
    Call read_data_from_file('example.dat', readData)

    ! Print the read data
    Print *, "Data read from file:", readData

Contains

    Subroutine write_data_to_file(filename, data)
        Character(len=*), Intent(in) :: filename
        Integer, Dimension(:), Intent(in) :: data
        Open(unit=10, file=filename, status='replace', action='write')
        Write(10, *) data
        Close(10)
    End Subroutine write_data_to_file

    Subroutine read_data_from_file(filename, data)
        Character(len=*), Intent(in) :: filename
        Integer, Dimension(:), Intent(out) :: data
        Open(unit=10, file=filename, status='old', action='read')
        Read(10, *) data
        Close(10)
    End Subroutine read_data_from_file

End Program FortranFileIO