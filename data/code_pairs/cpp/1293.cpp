#include <iostream>
#include <openacc.h>
#include <cstdlib>

int main() {
    int num_devices = acc_get_num_devices(acc_device_nvidia);

    // Check if NVIDIA devices are available
    if (num_devices == 0) {
        std::cout << "No NVIDIA devices available - Exiting" << std::endl;
        return EXIT_FAILURE;
    }

    // Initialize the device
    acc_init(acc_device_nvidia);

    int n = 0;

    // Set the device number
    acc_set_device_num(n, acc_device_nvidia);

    // Check if the device number is set correctly to 0
    if (acc_get_device_num(acc_device_nvidia) != 0) {
        std::cout << "Device not set correctly - Exiting" << std::endl;
        return EXIT_FAILURE;
    }

    // Check if more than one NVIDIA devices are available
    if (num_devices > 1) {
        n = 1;

        // Set the device number to 1 for the second device
        acc_set_device_num(n, acc_device_nvidia);

        // Check if the device number is set correctly to 1
        if (acc_get_device_num(acc_device_nvidia) != 1) {
            std::cout << "Second device not set correctly - Exiting" << std::endl;
            return EXIT_FAILURE;
        }
    }

    // Shutdown the device
    acc_shutdown(acc_device_nvidia);

    return EXIT_SUCCESS;
}