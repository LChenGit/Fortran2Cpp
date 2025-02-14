! main.f90: Contains the main program and associated subroutines

program main_program
    ! This is the main program block where execution begins
    implicit none
    
    real :: a(5) = [1.0, 2.0, 3.0, 4.0, 5.0]  ! Sample array 'a'
    integer :: i                          ! Index variable

    write(*,*) "Original array 'a':"
    do i = 1, 5
        write(*,*) a(i)
    end do
    
    call finc(a, 5)  ! Call the finc subroutine to modify array 'a'
    
    write(*,*) "Modified array 'a' after calling finc:"
    do i = 1, 5
        write(*,*) a(i)
    end do
end program main_program

! Subroutine to modify the first element of the array
subroutine finc(a, size)
    real :: a(:)
    integer :: size

    if (size > 0) then
        a(1) = 0.8
    endif
end subroutine finc