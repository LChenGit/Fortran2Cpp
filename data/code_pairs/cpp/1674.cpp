#ifndef GTK_HL_ACCELERATOR_HPP
#define GTK_HL_ACCELERATOR_HPP

#include <iostream>
#include <string>

class GtkHlAccelerator {
public:
    static void hl_gtk_widget_add_accelerator(const std::string& widget, const std::string& signal, const std::string& accel_group, const std::string& accel_key, int accel_mods = 4 /* GDK_CONTROL_MASK */, int accel_flags = 1 /* GTK_ACCEL_VISIBLE */) {
        std::cout << "Adding accelerator to widget: " << widget << std::endl;
        std::cout << "Signal: " << signal << ", Accel Group: " << accel_group << std::endl;
        std::cout << "Accel Key: " << accel_key << ", Mods: " << accel_mods << ", Flags: " << accel_flags << std::endl;
    }
};

#endif // GTK_HL_ACCELERATOR_HPP