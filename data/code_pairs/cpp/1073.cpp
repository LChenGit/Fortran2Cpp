// aot_fun_declaration_module.h
#ifndef AOT_FUN_DECLARATION_MODULE_H
#define AOT_FUN_DECLARATION_MODULE_H

namespace aot_fun_declaration_module {

    struct aot_fun_type {
        int handle = 0;
        int arg_count = 0;

        // Constructor (optional, since default member initializers are used)
        aot_fun_type(int h = 0, int a = 0) : handle(h), arg_count(a) {}
    };

} // namespace aot_fun_declaration_module

#endif // AOT_FUN_DECLARATION_MODULE_H