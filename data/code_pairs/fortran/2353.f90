! main.f90
program main
  implicit none

  enum, bind(c)
    enumerator :: sun, mon = 2    
    enum, bind(c)
      enumerator :: apple, mango
    end enum  
    enumerator :: wed = 1    
  end enum  

  print *, "This is a placeholder program to define enums."
end program main