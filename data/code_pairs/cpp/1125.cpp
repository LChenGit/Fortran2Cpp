#include <iostream>

namespace m3 {
  class t {
    public:
      int value; // Public member variable
  };
}

int main() {
  m3::t obj;
  obj.value = 5; // Assign a value
  
  // Check if the assignment is successful
  if (obj.value == 5) {
    std::cout << "Test passed." << std::endl;
  } else {
    std::cout << "Test failed." << std::endl;
  }
  
  return 0;
}