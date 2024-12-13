MODULE n_layers
    IMPLICIT NONE
CONTAINS
    FUNCTION calculate_layers(x) RESULT(y)
        INTEGER, INTENT(IN) :: x
        INTEGER :: y
        ! Example functionality
        y = x * 2
    END FUNCTION calculate_layers
END MODULE n_layers