module module_geometry
    implicit none

    integer :: Nnco, Nnco0, Nncoold
    integer :: Npf, Npb, Npo
    integer :: Nsamp, Nsampold
    double precision :: Ls, Ls0, Lsold   
    double precision :: Lx, Lx0, Lxold   

    integer, allocatable :: oxrow(:), oxsum(:)      
    integer, allocatable :: pbrow(:), pbsum(:)      
    integer, allocatable :: whereisnode(:)          

    double precision, allocatable :: x(:), y(:), x0(:), y0(:) 
    double precision, allocatable :: xo(:), yo(:)             
    double precision, allocatable :: xb(:), yb(:)             
    double precision, allocatable :: s(:)                     
    double precision, allocatable :: th(:)                    
    double precision, allocatable :: c(:)                     
    double precision, allocatable :: dU(:)                    
    double precision, allocatable :: E(:)                     
end module module_geometry