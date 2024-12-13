program test_quicksort
    implicit none
    real*8, dimension(5) :: test_array
    real*8, dimension(5) :: expected_array

    ! Test array and expected sorted array
    test_array = (/ 3.0, 1.0, 4.0, 1.5, 2.0 /)
    expected_array = (/ 1.0, 1.5, 2.0, 3.0, 4.0 /)

    ! Call the quicksort subroutine
    call quicksort(test_array, 1, size(test_array))

    ! Check if the sorted array matches the expected array
    if (all(test_array == expected_array)) then
        print *, 'Quicksort test passed.'
    else
        print *, 'Quicksort test failed.'
        print *, 'Result:', test_array
        print *, 'Expected:', expected_array
    end if

contains

    recursive subroutine quicksort(a, lo0, hi)
        real*8 a(:)
        integer lo0, hi
        integer i, j
        real*8 pivot, t

        if (lo0 >= hi) return
        pivot = a((lo0+hi) / 2)
        i = lo0
        j = hi
        do while (i <= j)
            do while (a(i) < pivot)
                i = i + 1
            end do
            do while (a(j) > pivot)
                j = j - 1
            end do
            if (i <= j) then
                t = a(i)
                a(i) = a(j)
                a(j) = t
                i = i + 1
                j = j - 1
            end if
        end do
        if (lo0 < j) call quicksort(a, lo0, j)
        if (i < hi) call quicksort(a, i, hi)
    end subroutine

end program