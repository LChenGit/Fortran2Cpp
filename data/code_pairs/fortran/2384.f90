#ifdef SPACE_2D
subroutine BoundaryMassForceMatrix2D(FiS, FiN, TT, RN) 
  implicit none
  double precision, intent(in) :: FiS, FiN 
  double precision, dimension(1:2,1:2), intent(in) :: TT
  double precision, dimension(1:2,1:2), intent(inout) :: RN

  RN(1,1) = FiS * TT(1,1) * TT(1,1) + FiN * TT(2,1) * TT(2,1)
  RN(1,2) = (FiS - FiN) * TT(1,1) * TT(2,1)
  RN(2,1) = RN(1,2)
  RN(2,2) = FiS * TT(2,1) * TT(2,1) + FiN * TT(1,1) * TT(1,1)
end subroutine BoundaryMassForceMatrix2D
#endif