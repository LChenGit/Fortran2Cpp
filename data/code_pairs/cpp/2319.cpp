#ifndef C_FUNCTIONS_H
#define C_FUNCTIONS_H

extern "C" {
    void C_makeobj(int n);
    void C_closeobj();
    void C_delobj(int n);
    int C_genobj();
    int C_getopenobj();
    void C_callobj(int n);
    short C_isobj(int n);
}

#endif // C_FUNCTIONS_H