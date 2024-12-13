program tam_fijo
    implicit none
    real, dimension(5) :: arreglo_1
    real, dimension(-1:3) :: arreglo_2 = (/1, 2, 3, 4, 5/)
    integer, dimension (5,5) :: matriz
    integer, dimension(0:4) :: arreglo_3
    integer, dimension(0:4, 1:6) :: matriz_2
    integer, dimension(4,4):: matriz_3

    print *, "Posición 1 de arreglo_1: ", arreglo_1(1)
    print *, "Posición (2, 6) de matriz_2: ", matriz_2(2, 6)
    print *, "matriz_3(1:4:1): ", matriz_3(1:4:1, 1:4:1) ! This is not directly executable in Fortran
    print *, "matriz_3(1:4:1): ", matriz_3(1:4:1, 3:1:-1) ! This is not directly executable in Fortran
    
end program tam_fijo