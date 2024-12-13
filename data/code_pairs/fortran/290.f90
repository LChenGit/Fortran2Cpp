module TransferBug
    implicit none

    type :: ByteType
        character(len=1) :: singleByte
    end type ByteType

contains

    function StringToBytes(v) result(bytes)
        character(len=*), intent(in) :: v
        type(ByteType), allocatable :: bytes(:)
        integer :: i

        allocate(bytes(len(v)))
        do i = 1, len(v)
            bytes(i)%singleByte = v(i:i)
        end do
    end function StringToBytes

    subroutine BytesToString(bytes, string)
        type(ByteType), intent(in) :: bytes(:)
        character(len=*), intent(out) :: string
        integer :: numChars, i

        numChars = size(bytes)
        string = ''
        do i = 1, numChars
            string(i:i) = bytes(i)%singleByte
        end do
    end subroutine BytesToString

end module TransferBug

program main
    use TransferBug
    implicit none
    
    character(len=100) :: str = "Hello, world!"
    character(len=100) :: resultStr

    call BytesToString(StringToBytes(str), resultStr)

    if (trim(resultStr) /= trim(str)) then
        print *, "Conversion Failed"
    else
        print *, "Conversion Successful: ", trim(resultStr)
    end if
end program main