MODULE wannier_new
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(p=15)
  INTEGER, PARAMETER :: ningx = 10
  LOGICAL :: use_wannier = .FALSE.
  LOGICAL :: rkmesh = .FALSE.
  LOGICAL :: plot_wannier = .FALSE.
  LOGICAL :: use_energy_int = .FALSE.
  LOGICAL :: print_wannier_coeff = .FALSE.
  INTEGER :: nwan = 0
  INTEGER :: plot_wan_num = 0
  INTEGER :: plot_wan_spin = 0
  REAL(KIND=DP), ALLOCATABLE :: wan_pot(:,:)
  REAL(KIND=DP), ALLOCATABLE :: wannier_energy(:,:)
  REAL(KIND=DP), ALLOCATABLE :: wannier_occ(:,:,:)
  COMPLEX(KIND=DP), ALLOCATABLE :: pp(:,:)
  COMPLEX(KIND=DP), ALLOCATABLE :: coef(:,:,:)
        
  TYPE ingredient
     INTEGER :: l = 0
     INTEGER :: m = 0
     INTEGER :: iatomwfc = 0
     REAL(KIND=DP) :: c = 0.0_DP
  END TYPE ingredient
  
  TYPE wannier_data
     INTEGER :: iatom = 0
     INTEGER :: ning = 0
     REAL(KIND=DP) :: bands_from = 0.0_DP
     REAL(KIND=DP) :: bands_to = 0.0_DP
     TYPE(ingredient), DIMENSION(ningx) :: ing
  END TYPE wannier_data
  
  TYPE(wannier_data), ALLOCATABLE :: wan_in(:,:)
END MODULE wannier_new