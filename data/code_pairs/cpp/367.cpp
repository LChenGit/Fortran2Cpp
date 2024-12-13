#ifndef UDS_SPEC_H
#define UDS_SPEC_H

struct UDS_SPEC {
    int field1;
    double field2;
};

void UDS_SPEC_COPY(UDS_SPEC& D, const UDS_SPEC& S);

#endif // UDS_SPEC_H