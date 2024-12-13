SUBROUTINE PYGDIR(X, Q2, P2, Q02, XPGA)
      IMPLICIT DOUBLE PRECISION(A-H, O-Z)
      IMPLICIT INTEGER(I-N)
      DOUBLE PRECISION XPGA(-6:6), PMC, PMB, AEM2PI, XTMP, CGAM
      INTEGER KFL, KF

      DATA PMC/1.3D0/, PMB/4.6D0/, AEM2PI/0.0011614D0/

      DO KFL = -6, 6
        XPGA(KFL) = 0D0
      END DO

      XTMP = (X**2 + (1D0-X)**2) * (-LOG(X)) - 1D0
      CGAM = 3D0 * AEM2PI * X * (XTMP * (1D0 + P2 / (P2 + Q02)) + 6D0 * X * (1D0 - X))

      XPGA(1) = (1D0 / 9D0) * CGAM
      XPGA(2) = (4D0 / 9D0) * CGAM
      XPGA(3) = (1D0 / 9D0) * CGAM

      DO KF = 1, 5
        XPGA(-KF) = XPGA(KF)
      END DO

      END