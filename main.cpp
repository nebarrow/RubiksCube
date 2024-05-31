#include "cube/cube.h"
#include "cube/window.h"
#include "utils/utility.h"

int main() {
    Window window(800, 600, "Rubik's Cube");
    Cube cube;
    Utility utility(window.getWindow());
    window.start();

    return 0;
}
