subroutine enq_v1_iae_code(n, iae, s)
    integer, intent(in) :: n, s
    integer, intent(inout) :: iae
    
    if (s /= 0) return
    iae = n
end subroutine enq_v1_iae_code