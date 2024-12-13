#include <iostream>
#include <string>

class DataProc {
public:
    int nproc;              
    int mynum;              
    std::string appnproc; 
    std::string appmynum; 
    bool lpr;                
    std::string procstrg; 

    DataProc() : nproc(0), mynum(0), appnproc(4, ' '), appmynum(4, ' '), lpr(false), procstrg(8, ' ') {}
};