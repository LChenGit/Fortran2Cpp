// file: socket_comm.h
#include <cstdint>
#include <cstddef>

extern "C" {
    void fsi_fsicommc2socket_plain_port_create_client_instance(int64_t self, void* host, int32_t port, int32_t buffer_size);
    void fsi_fsicommc2socket_plain_port_destroy_instance(int64_t self);
    void fsi_fsicommc2socket_plain_port_transferCoordinates(int64_t self, const int32_t* coordId, int32_t coordId_len, const int32_t* offsets, int32_t offsets_len, int32_t hosts_len, void** hosts);
    void fsi_fsicommc2socket_plain_port_startDataTransfer(int64_t self);
    void fsi_fsicommc2socket_plain_port_endDataTransfer(int64_t self, int32_t* ack);
}