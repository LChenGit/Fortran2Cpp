#ifndef ENVIRONMENTVARIABLESETTER_H
#define ENVIRONMENTVARIABLESETTER_H

#include <cstdlib>

void SetUVMTestName() {
    #ifdef _WIN32
    SetEnvironmentVariable("UVM_TESTNAME", "wb_periph_subsys_test_base");
    #else
    setenv("UVM_TESTNAME", "wb_periph_subsys_test_base", 1);
    #endif
}

#endif // ENVIRONMENTVARIABLESETTER_H