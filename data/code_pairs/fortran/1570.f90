module globals
    implicit none

    integer :: rank

    integer :: nbmin         
    integer :: nbmax         
    integer :: nbrootx       
    integer :: nbrooty       
    integer :: nbrootz       
    integer :: maxcells_x    
    integer :: maxcells_y    
    integer :: maxcells_z    
    integer :: maxlev        
    integer :: nbLocal       
    integer :: nbActive      

    integer :: it            
    real :: time             
    real :: dt               
    integer :: nextout       

    integer :: start_mark     
    integer :: logu           
    character(80) :: logfile  
    character(15) :: host     

    real :: timings(3)

end module globals

program test_globals
    use globals
    implicit none

    rank = 1
    nbmin = 10
    nbmax = 20
    time = 0.0
    dt = 0.1

    print *, "Testing Fortran globals module"
    print *, "rank:", rank
    print *, "nbmin:", nbmin
    print *, "nbmax:", nbmax
    print *, "time:", time
    print *, "dt:", dt
end program test_globals