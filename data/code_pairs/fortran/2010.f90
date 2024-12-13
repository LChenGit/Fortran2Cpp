! file: socket_comm.f90
module socket_comm_interface
    use, intrinsic :: iso_c_binding
    implicit none

    interface
        subroutine fsi_fsicommc2socket_plain_port_create_client_instance(self, host, port, buffer_size) bind(c)
            import :: c_long_long, c_ptr, c_int
            integer(c_long_long), value :: self
            type(c_ptr), value :: host
            integer(c_int), value :: port
            integer(c_int), value :: buffer_size
        end subroutine fsi_fsicommc2socket_plain_port_create_client_instance

        subroutine fsi_fsicommc2socket_plain_port_destroy_instance(self) bind(c)
            import :: c_long_long
            integer(c_long_long), value :: self
        end subroutine fsi_fsicommc2socket_plain_port_destroy_instance

        subroutine fsi_fsicommc2socket_plain_port_transferCoordinates(self, coordId, coordId_len, offsets, offsets_len, hosts, hosts_len) bind(c)
            import :: c_long_long, c_ptr, c_int
            integer(c_long_long), value :: self
            integer(c_int), dimension(*), intent(in) :: coordId
            integer(c_int), value :: coordId_len
            integer(c_int), dimension(*), intent(in) :: offsets
            integer(c_int), value :: offsets_len
            integer(c_int), value :: hosts_len
            type(c_ptr), dimension(*), intent(in) :: hosts
        end subroutine fsi_fsicommc2socket_plain_port_transferCoordinates

        subroutine fsi_fsicommc2socket_plain_port_startDataTransfer(self) bind(c)
            import :: c_long_long
            integer(c_long_long), value :: self
        end subroutine fsi_fsicommc2socket_plain_port_startDataTransfer

        subroutine fsi_fsicommc2socket_plain_port_endDataTransfer(self, ack) bind(c)
            import :: c_long_long, c_int
            integer(c_long_long), value :: self
            integer(c_int), intent(inout) :: ack
        end subroutine fsi_fsicommc2socket_plain_port_endDataTransfer
    end interface

end module socket_comm_interface