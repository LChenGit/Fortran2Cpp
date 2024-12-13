MODULE ModifiedvKrm_mod

   IMPLICIT NONE

CONTAINS

   SUBROUTINE Mod_vKrm ( Ht, Ucmp, Spec )

      IMPLICIT NONE

      REAL(8), INTENT(IN)    :: Ht
      REAL(8), INTENT(IN)    :: UCmp
      REAL(8), INTENT(OUT)   :: Spec(:,:)

      Spec = 0.0_8

   END SUBROUTINE Mod_vKrm

   SUBROUTINE ScaleMODVKM(Ht,UCmp, LambdaU, LambdaV, LambdaW)

      IMPLICIT NONE

      REAL(8), INTENT(IN)  :: Ht
      REAL(8), INTENT(IN)  :: UCmp

      REAL(8), INTENT(OUT) :: LambdaU
      REAL(8), INTENT(OUT) :: LambdaV
      REAL(8), INTENT(OUT) :: LambdaW

   END SUBROUTINE ScaleMODVKM

   FUNCTION FindZ0(z, sigma, U, f) RESULT(FindZ0Res)

      IMPLICIT NONE

      REAL(8)                :: FindZ0Res
      REAL(8), INTENT(IN)    :: z
      REAL(8), INTENT(IN)    :: sigma
      REAL(8), INTENT(IN)    :: U
      REAL(8), INTENT(IN)    :: f

      FindZ0Res = 1.0_8

   END FUNCTION FindZ0

   FUNCTION CalcDiff(z0Guess, z, sigma, U, f) RESULT(CalcDiffRes)

      IMPLICIT NONE

      REAL(8)                :: CalcDiffRes
      REAL(8), INTENT(IN)    :: z0Guess
      REAL(8), INTENT(IN)    :: z
      REAL(8), INTENT(IN)    :: sigma
      REAL(8), INTENT(IN)    :: U
      REAL(8), INTENT(IN)    :: f

      CalcDiffRes = 0.0_8

   END FUNCTION CalcDiff

END MODULE ModifiedvKrm_mod