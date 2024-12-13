module m_rp_global_var
    implicit none
    type :: MethStruct
        character(len=:), allocatable :: tlag, det, rot, qcflag, foot
    end type MethStruct

    type :: RUsetupStruct
        character(len=:), allocatable :: meth
    end type RUsetupStruct

    type :: RPsetupStruct
        character(len=:), allocatable :: bu_corr, calib_aoa
        logical :: bu_multi, calib_cw, filter_by_raw_flags
        real(8) :: offset(3)
        logical :: out_st, filter_sr, filter_al, out_qc_details
        logical :: out_raw, out_bin_sp, out_bin_og, out_full_sp, out_full_cosp
    end type RPsetupStruct

    type :: EddyProProjStruct
        logical :: use_extmd_file, wpl, out_md, out_fluxnet, out_full
        logical :: out_avrg_cosp, out_biomet, fcc_follows, make_dataset
        character(len=:), allocatable :: biomet_data, hf_meth
    end type EddyProProjStruct

    type :: TestStruct
        logical :: sr, ar, do, al, sk, ds, tl, aa, ns
    end type TestStruct

    type(MethStruct) :: Meth
    type(RUsetupStruct) :: RUsetup
    type(RPsetupStruct) :: RPsetup
    type(EddyProProjStruct) :: EddyProProj
    type(TestStruct) :: Test
end module m_rp_global_var

program TestConfiguration
    use m_rp_global_var
    call ConfigureForMdRetrieval()
    
    ! Optionally, print some variables to verify
    print *, 'Meth%tlag = ', Meth%tlag
    print *, 'EddyProProj%use_extmd_file = ', EddyProProj%use_extmd_file
end program TestConfiguration

subroutine ConfigureForMdRetrieval()
    use m_rp_global_var
    Meth%tlag = 'none'
    ! The rest of the initialization code as per previous example.
    ! Initialize other variables similarly
end subroutine ConfigureForMdRetrieval