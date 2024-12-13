module param
    implicit none
    integer, parameter :: ACCU = selected_real_kind(15, 307)
    integer, parameter :: ALL_MF = 42
    real(ACCU), parameter :: MU_TOLERANCE = 1.0_ACCU * 10.0_ACCU**(-4)
    real(ACCU), parameter :: DGEN_TOLERANCE = 0.1_ACCU * 10.0_ACCU**(-9)

    type :: rotor
        real(ACCU) :: A, B, C
    end type rotor

    type :: potential
        real(ACCU) :: Vj, Vk, Vm
    end type potential

    integer, private :: dim = 0
    integer, private :: K_LIMIT = 4

contains
    function is_linear(mol) result(linear)
        implicit none
        type(rotor), intent(in) :: mol
        logical :: linear

        linear = (mol%A == 0.0_ACCU .and. mol%C == 0.0_ACCU)
    end function is_linear

    subroutine set_k_limit(k)
        integer, intent(in) :: k
        if (k /= 0 .and. k /= 4) then
            print *, 'set_k_limit(): Only K=0 or K=4 supported at the moment'
            stop
        end if
        K_LIMIT = k
    end subroutine set_k_limit

    function get_k_limit() result(k)
        integer :: k
        k = K_LIMIT
    end function get_k_limit

    subroutine setdim(d)
        integer, intent(in) :: d
        dim = d
    end subroutine setdim

    function getdim() result(d)
        integer :: d
        d = dim
    end function getdim
end module param