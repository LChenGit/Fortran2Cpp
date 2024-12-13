Real(8) Function stheta_sq(x)
    Implicit None
    Real(8), Intent(In) :: x

    If (x .Le. -0.5d0) Then
        stheta_sq = 0.d0
    ElseIf (x .Lt. 0.5d0) Then
        stheta_sq = x + 0.5d0
    Else
        stheta_sq = 1.d0
    End If
End Function stheta_sq