program hello_world
    implicit none
    
    open(unit=1, file='output.txt', status='replace')
    write (unit=1, fmt=*) 'Hello, World!'
    close(1)
    
end program hello_world