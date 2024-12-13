! Module containing the subroutine and its dependencies
MODULE collect_info_mod
    IMPLICIT NONE
    TYPE :: collect_info_type
        ! Define members of the type here. For demonstration:
        INTEGER :: dummy
    END TYPE collect_info_type

CONTAINS

    SUBROUTINE collect_the_info(info)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER :: pos, nima
        LOGICAL :: use_ph_images
        INTEGER :: my_image_id, nimage, nqs, nat, irr_iq, inter_image_comm
        
        use_ph_images = .FALSE. ! Assume a way to set this based on some logic or external input
        my_image_id = 0         ! Assume values for demonstration purposes
        nimage = 1
        nqs = 10
        nat = 50
        irr_iq = 7
        inter_image_comm = 1

        IF (use_ph_images) THEN
            pos = my_image_id + 1
            nima = nimage
        ELSE
            pos = 1
            nima = 1
        ENDIF

        CALL init_collect_info(info, nqs, nat, nima, irr_iq)
        CALL save_collect_info(info, nqs, nat, pos, .TRUE., .TRUE., .TRUE., .TRUE.)

        IF (use_ph_images) CALL comm_collect_info(info, inter_image_comm)
    END SUBROUTINE collect_the_info

    ! Dummy implementations for demonstration
    SUBROUTINE init_collect_info(info, nqs, nat, nima, irr_iq)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: nqs, nat, nima, irr_iq
    END SUBROUTINE init_collect_info

    SUBROUTINE save_collect_info(info, nqs, nat, pos, comp_irr_iq, done_irr_iq, comp_iq, done_iq)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: nqs, nat, pos
        LOGICAL, INTENT(IN) :: comp_irr_iq, done_irr_iq, comp_iq, done_iq
    END SUBROUTINE save_collect_info

    SUBROUTINE comm_collect_info(info, inter_image_comm)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: inter_image_comm
    END SUBROUTINE comm_collect_info

END MODULE collect_info_mod

! Test program
PROGRAM test_collect_the_info
    USE collect_info_mod
    IMPLICIT NONE
    TYPE(collect_info_type) :: info

    CALL collect_the_info(info)

    PRINT *, "Test ran successfully"
END PROGRAM test_collect_the_info