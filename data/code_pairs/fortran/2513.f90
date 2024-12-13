module netcdf
    implicit none
contains
    subroutine openFile(filename)
        character(len=*), intent(in) :: filename
        print *, 'File opened: ', trim(filename)
    end subroutine openFile

    subroutine closeFile()
        print *, 'File closed.'
    end subroutine closeFile
end module netcdf