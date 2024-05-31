#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../utils/shaders.h"

struct Cubes {
    glm::vec3 colors[6];
    int position[3];
    int point;
    glm::mat4 modelMatrix = glm::mat4(1.0f);
};

class Cube {
public:
    static void drawScene();
    static void disassembling(GLFWwindow *window);
    static void movement(GLFWwindow* window);
    Cube();
    ~Cube();
    static GLuint VBO, VAO;
    static Cubes cubes[3][3][3];
    glm::vec3 colors[27][6];
    static glm::vec3 positions[27];
private:
    struct Colors {
        glm::vec3 colors[6];
    };

    void setColors(glm::vec3 colors[6], glm::vec3 color0, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3,
                       glm::vec3 color4, glm::vec3 color5);

    static void turnHor(int verge, GLFWwindow *window, int direction);

    static void turnVer(int verge, GLFWwindow *window, int direction);

    static void turnSide(int verge, GLFWwindow *window, int direction);

    static void U(GLFWwindow *window);

    static void U2(GLFWwindow *window);

    static void U1(GLFWwindow *window);

    static void F(GLFWwindow *window);

    static void F1(GLFWwindow *window);

    static void F2(GLFWwindow *window);

    static void R(GLFWwindow *window);

    static void R1(GLFWwindow *window);

    static void R2(GLFWwindow *window);

    static void L(GLFWwindow *window);

    static void L1(GLFWwindow *window);

    static void PifPafGreen(GLFWwindow *window);

    static void PifPafOrange(GLFWwindow *window);

    static void PifPafBlue(GLFWwindow *window);

    static void PifPaf(GLFWwindow *window);

    static void Infarct(GLFWwindow *window);

    static void turnLeft(int x, int y, int z);

    static void turnDown(int x, int y, int z);

    static void turnUpFace(int x, int y, int z);

    static void turnVertical(int verge, int direction);

    static void turnHorizontal(int verge, int direction);

    static void turnToTheSide(int verge, int direction);

    static bool isCross();

    static bool isFullCross();

    static void changeSide(GLFWwindow* window);

    static void change(GLFWwindow* window);

    static void pifpaf1(GLFWwindow* window);

    static void sunflower_r(GLFWwindow* window);

    static void sunflower_l(GLFWwindow* window);

    static void solveCross(GLFWwindow* window);

    static bool checkFirstLevel();

    static void buildFirstLevel(GLFWwindow* window);

    static bool checkSecondLevel();

    static void buildSecondLevel(GLFWwindow* window);

    static void buildYellowCross(GLFWwindow* window);

    static bool checkEdges(GLFWwindow* window);

    static void buildEdges(GLFWwindow* window);

    static bool checkUpCross();

    static void buildUpCross(GLFWwindow* window);

    static bool checkFullCube();

    static void solve(GLFWwindow* window);
};
