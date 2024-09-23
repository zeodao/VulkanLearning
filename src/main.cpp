#include "triangle.h"

int main(int, char**) {
  // setenv("DISPLAY", "192.168.21.216:10.0", 1);
  // setenv("DISPLAY", "192.168.5.18:10.0", 1);
  // setenv("DISPLAY", ":0", 1);
  TriangleApp app;
  try {
    app.Run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
