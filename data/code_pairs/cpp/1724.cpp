#ifndef MPHYS_INTERFACE_H
#define MPHYS_INTERFACE_H

void mphys_thompson09_interface();
void mphys_thompson07_interface();
void mphys_morrison_interface();

namespace mphys_interface {

void mphys_column(int scheme_id);

} // namespace mphys_interface

#endif // MPHYS_INTERFACE_H