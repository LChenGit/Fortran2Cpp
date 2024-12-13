real function db(x)
    real, intent(in) :: x
    db = -99.0
    if (x > 1.259e-10) then
        db = 10.0 * log10(x)
    endif
end function db