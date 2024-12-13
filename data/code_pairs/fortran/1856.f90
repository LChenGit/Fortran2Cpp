module para
contains
   function bobo(n)
       integer, intent(in) :: n
       character(len=n) :: bobo
       bobo = "1234567890"(1:n)
   end function bobo
end module para