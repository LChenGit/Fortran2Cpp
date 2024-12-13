program test_integration
    implicit none
    double precision :: result, error
    double precision, external :: f
    double precision, parameter :: a = 0.0d0, b = 1.0d0
    double precision, parameter :: epsabs = 1.0e-10, epsrel = 1.0e-10

    ! Assuming qag is a subroutine from QUADPACK
    ! This is a mock-up for demonstration
    call qag(f, a, b, epsabs, epsrel, result, error)
    print *, 'Integration result: ', result
    print *, 'Expected result: ', 1.0 / 3.0
    print *, 'Estimated error: ', error

contains

    ! Mock implementation of qag, for demonstration
    subroutine qag(f, a, b, epsabs, epsrel, result, error)
        implicit none
        double precision, intent(in) :: a, b, epsabs, epsrel
        double precision, external :: f
        double precision, intent(out) :: result, error
        double precision :: h, fa, fb, m, fm, i1, i2
        
        h = b - a
        fa = f(a)
        fb = f(b)
        m = (a + b) / 2.0d0
        fm = f(m)
        
        i1 = h * (fa + 4.0d0*fm + fb) / 6.0d0
        i2 = h * (fa + fb) / 2.0d0
        
        result = i1
        error = abs(i1 - i2)
    end subroutine qag

    ! Function to integrate
    double precision function f(x)
        double precision, intent(in) :: x
        f = x**2
    end function f

end program test_integration