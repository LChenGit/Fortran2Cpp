program format_output
    character(10) :: fmt = "(en0.2)"
    open(unit=10, file='output.txt', status='replace')
    write(10, fmt) 3.0
    close(10)
end program format_output