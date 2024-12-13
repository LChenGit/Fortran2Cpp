! Assuming 1.inc contains a simple subroutine to add two numbers
subroutine add(a, b, result)
    implicit none
    integer, intent(in) :: a, b
    integer, intent(out) :: result

    result = a + b
end subroutine add