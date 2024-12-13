program testXML
    implicit none

    call createXML()
    call checkXML()

contains

    subroutine createXML()
        ! Create the XML file with specified content
        open(unit=10, file='test.xml', status='replace', action='write')
        write(10, '(a)') '<?xml version="1.0" encoding="UTF-8"?>'
        write(10, '(a)') '<!DOCTYPE html>'
        write(10, '(a)') '<!-- Parameter Entity: copy "http://www.uszla.me.uk/entities" -->'
        write(10, '(a)') '<html>'
        write(10, '(a)') '</html>'
        close(10)
    end subroutine createXML

    subroutine checkXML()
        character(len=1024) :: line
        integer :: ioStatus

        open(unit=11, file='test.xml', status='old', action='read')

        do
            read(11, '(A)', iostat=ioStatus) line
            if (ioStatus /= 0) exit
            if (index(line, '<!DOCTYPE html>') /= 0) then
                print *, "Found DOCTYPE declaration."
            endif
            if (index(line, 'Parameter Entity:') /= 0) then
                print *, "Found Parameter Entity comment."
            endif
            if (index(line, '<html>') /= 0) then
                print *, "Found opening <html> element."
            endif
            if (index(line, '</html>') /= 0) then
                print *, "Found closing </html> element."
            endif
        end do
        close(11)

        print *, "Basic XML content check completed."
    end subroutine checkXML

end program testXML