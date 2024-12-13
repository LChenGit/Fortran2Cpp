Module R3dotModule
    Implicit None
Contains
    Real (8) Function r3dot (x, y)
        Implicit None
        Real (8), Intent (In) :: x(3)
        Real (8), Intent (In) :: y(3)
        r3dot = x(1) * y(1) + x(2) * y(2) + x(3) * y(3)
    End Function r3dot
End Module R3dotModule