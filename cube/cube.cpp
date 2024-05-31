#include <iostream>
#include "cube.h"
#include "../utils/utility.h"

GLuint Cube::VAO = 0;
GLuint Cube::VBO = 0;

Cubes Cube::cubes[3][3][3] = {};
glm::vec3 Cube::positions[27] = {};

Cube::Cube() {

    GLfloat vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    glm::vec3 red = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 black = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 green = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 blue = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 white = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 orange = glm::vec3(1.0f, 0.4f, 0.0f);
    glm::vec3 yellow = glm::vec3(1.0f, 1.0f, 0.0f);

    setColors(colors[0], red, black, green, black, white, black);
    setColors(colors[1], black, black, green, black, white, black);
    setColors(colors[2], black, orange, green, black, white, black);
    setColors(colors[3], red, black, green, black, black, black);
    setColors(colors[4], black, black, green, black, black, black);
    setColors(colors[5], black, orange, green, black, black, black);
    setColors(colors[6], red, black, green, black, black, yellow);
    setColors(colors[7], black, black, green, black, black, yellow);
    setColors(colors[8], black, orange, green, black, black, yellow);
    setColors(colors[9], red, black, black, black, white, black);
    setColors(colors[10], black, black, black, black, white, black);
    setColors(colors[11], black, orange, black, black, white, black);
    setColors(colors[12], red, black, black, black, black, black);
    setColors(colors[13], black, black, black, black, black, black);
    setColors(colors[14], black, orange, black, black, black, black);
    setColors(colors[15], red, black, black, black, black, yellow);
    setColors(colors[16], black, black, black, black, black, yellow);
    setColors(colors[17], black, orange, black, black, black, yellow);
    setColors(colors[18], red, black, black, blue, white, black);
    setColors(colors[19], black, black, black, blue, white, black);
    setColors(colors[20], black, orange, black, blue, white, black);
    setColors(colors[21], red, black, black, blue, black, black);
    setColors(colors[22], black, black, black, blue, black, black);
    setColors(colors[23], black, orange, black, blue, black, black);
    setColors(colors[24], red, black, black, blue, black, yellow);
    setColors(colors[25], black, black, black, blue, black, yellow);
    setColors(colors[26], black, orange, black, blue, black, yellow);

    int index = 0;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            for (int z = -1; z <= 1; ++z) {
                cubes[x + 1][y + 1][z + 1].position[0] = x;
                cubes[x + 1][y + 1][z + 1].position[1] = y;
                cubes[x + 1][y + 1][z + 1].position[2] = z;
                for (int j = 0; j < 6; ++j) {
                    cubes[x + 1][y + 1][z + 1].colors[j] = colors[index][j];
                }
                index++;
            }
        }
    }

    index = 0;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            for (int z = -1; z <= 1; ++z) {
                cubes[x + 1][y + 1][z + 1].position[0] = x;
                cubes[x + 1][y + 1][z + 1].position[1] = y;
                cubes[x + 1][y + 1][z + 1].position[2] = z;
                for (int j = 0; j < 6; ++j) {
                    cubes[x + 1][y + 1][z + 1].colors[j] = colors[index][j];
                }
                index++;
            }
        }
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    index = 0;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            for (int z = -1; z <= 1; ++z) {
                positions[index] = glm::vec3(x + 1, y + 1, z + 1);
                cubes[x + 1][y + 1][z + 1].point = index;
                index++;
            }
        }
    }
}

Cube::~Cube() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Cube::movement(GLFWwindow *window) {
    if (Utility::keys[GLFW_KEY_F]) {
        disassembling(window);
        Utility::keys[GLFW_KEY_F] = false;
    }

    if (Utility::keys[GLFW_KEY_G]) {
        solveCross(window);
        for (int i = 0; i < 2; ++i) {
            R(window);
            turnVer(1, window, 1);
            L1(window);
        }
        buildFirstLevel(window);
        buildSecondLevel(window);
        buildYellowCross(window);
        buildUpCross(window);
        buildEdges(window);
        solve(window);
        Utility::keys[GLFW_KEY_G] = false;
    }

}

void Cube::drawScene() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 Projection = glm::perspective(glm::radians(90.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(
            Utility::cameraPos,
            Utility::cameraPos + Utility::cameraFront,
            Utility::cameraUp
    );
    Shader* shader = download("../shaders/vertex.glslv", "../shaders/fragment.glslf");

    glBindVertexArray(VAO);
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            for (int z = 0; z < 3; ++z) {
                glm::mat4 Model = cubes[x][y][z].modelMatrix * glm::translate(glm::mat4(1.0f), positions[cubes[x][y][z].point] * 1.025f);
                glm::mat4 MVP = Projection * View * Model;
                for (int side = 0; side < 6; ++side) {
                    glUseProgram(shader->id);
                    GLuint MatrixID = glGetUniformLocation(shader->id, "MVP");
                    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
                    glUniform3fv(glGetUniformLocation(shader->id, "sideColors"), 1, glm::value_ptr(cubes[x][y][z].colors[side]));
                    glDrawArrays(GL_TRIANGLES, side * 6, 6);
                }
            }
        }
    }
    glBindVertexArray(0);
}

void Cube::disassembling(GLFWwindow *window) {
    int countOfOperations = 10;
    for (int i = 0; i < countOfOperations; ++i) {
        int direction = rand() % 2 ? 1 : -1;
        int verge = rand() % (2 + 1);
        turnVer(verge, window, direction);
        turnHor(verge, window, direction);
        turnSide(verge, window, direction);
    }
}

void Cube::setColors(glm::vec3 *colors, glm::vec3 color0, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3,
                         glm::vec3 color4, glm::vec3 color5) {
    colors[0] = color0;
    colors[1] = color1;
    colors[2] = color2;
    colors[3] = color3;
    colors[4] = color4;
    colors[5] = color5;
}


void Cube::U(GLFWwindow* window) {
    turnHor(2, window, 1);
}
void Cube::U2(GLFWwindow* window) {
    turnHor(2, window, 1);
    turnHor(2, window, 1);
}
void Cube::U1(GLFWwindow* window) {
    turnHor(2, window, -1);
}
void Cube::F(GLFWwindow* window) {
    turnSide(0, window, 1);
}
void Cube::F1(GLFWwindow* window) {
    turnSide(0, window, -1);
}
void Cube::F2(GLFWwindow* window) {
    F(window);
    F(window);
}
void Cube::R(GLFWwindow* window) {
    turnVer(0, window, 1);
}
void Cube::R1(GLFWwindow* window) {
    turnVer(0, window, -1);
}
void Cube::R2(GLFWwindow* window) {
    R(window);
    R(window);
}
void Cube::L(GLFWwindow* window) {
    turnVer(2, window, -1);
}
void Cube::L1(GLFWwindow* window) {
    turnVer(2, window, 1);

}

void Cube::PifPafGreen(GLFWwindow* window) {
    turnSide(2, window, -1);
    turnHor(2, window, 1);
    turnSide(2, window, 1);
    turnHor(2, window, -1);
}

void Cube::PifPafOrange(GLFWwindow* window) {
    turnVer(2, window, -1);
    turnHor(2, window, 1);
    turnVer(2, window, 1);
    turnHor(2, window, -1);
}

void Cube::PifPafBlue(GLFWwindow* window) {
    turnSide(0, window, 1);
    turnHor(2, window, 1);
    turnSide(0, window, -1);
    turnHor(2, window, -1);
}

void Cube::PifPaf(GLFWwindow* window) {
    R(window);
    U(window);
    R1(window);
    U1(window);
}

void Cube::Infarct(GLFWwindow* window) {
    U2(window);
    R(window);
    U2(window);
    R1(window);
    F2(window);
    U2(window);
    L1(window);
    U2(window);
    L(window);
    F2(window);
}

void Cube::sunflower_r(GLFWwindow *window) {
    changeSide(window);
    R(window);
    U(window);
    R(window);
    U(window);
    R(window);
    U1(window);
    R1(window);
    U1(window);
    R1(window);
    U1(window);
    change(window);
}

void Cube::sunflower_l(GLFWwindow* window) {
    changeSide(window);
    R1(window);
    U1(window);
    R1(window);
    U1(window);
    R1(window);
    U(window);
    R(window);
    U(window);
    R(window);
    U(window);
    change(window);
}

bool Cube::isCross() {
    if (cubes[1][2][1].colors[5] == cubes[2][2][1].colors[5] and cubes[1][2][1].colors[5] == cubes[0][2][1].colors[5] and cubes[1][2][1].colors[5] == cubes[1][2][2].colors[5] and cubes[1][2][1].colors[5] == cubes[1][2][0].colors[5]) {
        return true;
    }
    return false;
}

void Cube::turnLeft(int x, int y, int z) {
    glm::vec3 tempColors[6];
    tempColors[3] = cubes[x][y][z].colors[0];
    tempColors[0] = cubes[x][y][z].colors[2];
    tempColors[2] = cubes[x][y][z].colors[1];
    tempColors[1] = cubes[x][y][z].colors[3];
    tempColors[4] = cubes[x][y][z].colors[4];
    tempColors[5] = cubes[x][y][z].colors[5];
    for (int i = 0; i < 6; ++i) {
        cubes[x][y][z].colors[i] = tempColors[i];
    }
}

void Cube::turnDown(int x, int y, int z) {
    glm::vec3 tempColors[6];
    tempColors[0] = cubes[x][y][z].colors[4];
    tempColors[5] = cubes[x][y][z].colors[0];
    tempColors[1] = cubes[x][y][z].colors[5];
    tempColors[4] = cubes[x][y][z].colors[1];
    tempColors[3] = cubes[x][y][z].colors[3];
    tempColors[2] = cubes[x][y][z].colors[2];
    for (int i = 0; i < 6; ++i) {
        cubes[x][y][z].colors[i] = tempColors[i];
    }
}

void Cube::turnUpFace(int x, int y, int z) {
    glm::vec3 tempColors[6];
    tempColors[0] = cubes[x][y][z].colors[0];
    tempColors[5] = cubes[x][y][z].colors[3];
    tempColors[1] = cubes[x][y][z].colors[1];
    tempColors[4] = cubes[x][y][z].colors[2];
    tempColors[3] = cubes[x][y][z].colors[4];
    tempColors[2] = cubes[x][y][z].colors[5];
    for (int i = 0; i < 6; ++i) {
        cubes[x][y][z].colors[i] = tempColors[i];
    }
}

void Cube::turnVertical(int verge, int direction) {
    Colors tempColorsYellow[3][3][3];
    Colors tempColorsRed[3][3][3];
    Colors tempColorsOrange[3][3][3];
    Colors tempColorsWhite[3][3][3];

    for (int y = 0; y <= 2; ++y) {
        for (int i = 0; i < 6; ++i) {
            tempColorsRed[verge][y][0].colors[i] = cubes[verge][y][0].colors[i];
        }
    }
    for (int z = 2; z >= 0; --z) {
        for (int i = 0; i < 6; ++i) {
            tempColorsYellow[verge][2][z].colors[i] = cubes[verge][2][z].colors[i];
        }
    }
    for (int y = 0; y <= 2; ++y) {
        for (int i = 0; i < 6; ++i) {
            tempColorsOrange[verge][y][2].colors[i] = cubes[verge][y][2].colors[i];
        }
    }
    for (int z = 0; z <= 2; ++z) {
        for (int i = 0; i < 6; ++i) {
            tempColorsWhite[verge][0][z].colors[i] = cubes[verge][0][z].colors[i];
        }
    }

    if (direction == 1) {
        for (int z = 0; z <= 2; ++z) {
            for (int i = 0; i < 6; ++i) {
                cubes[verge][2][z].colors[i] = tempColorsRed[verge][z][0].colors[i];
            }
        }
        turnDown(verge, 2, 0);
        turnDown(verge, 2, 1);

        for (int z = 0; z <= 2; ++z) {
            for (int i = 0; i < 6; ++i) {
                cubes[verge][2-z][2].colors[i] = tempColorsYellow[verge][2][z].colors[i];
            }
        }
        turnDown(verge, 2, 2);
        turnDown(verge, 1, 2);
        turnDown(verge, 0, 2);

        for (int z = 0; z <= 2; ++z) {
            for (int i = 0; i < 6; ++i) {
                cubes[verge][0][z].colors[i] = tempColorsOrange[verge][z][2].colors[i];
            }
        }
        turnDown(verge, 0, 0);
        turnDown(verge, 0, 1);
        turnDown(verge, 0, 2);

        for (int z = 0; z <= 2; ++z) {
            for (int i = 0; i < 6; ++i) {
                cubes[verge][2-z][0].colors[i] = tempColorsWhite[verge][0][z].colors[i];
            }
        }
        turnDown(verge, 0, 0);
        turnDown(verge, 1, 0);
        turnDown(verge, 2, 0);
    } else if (direction == -1) {
        for (int i = 0; i < 3; ++i) {
            turnVertical(verge, 1);
        }
    }
}

void Cube::pifpaf1(GLFWwindow* window) {
    R(window);
    U(window);
    R1(window);
    U1(window);
    R(window);
}

void Cube::change(GLFWwindow *window) {
    for (int i = 0; i < 3; i++) {
        turnHor(i, window, 1);
    }
}

void Cube::changeSide(GLFWwindow* window) {
    for (int i = 0; i < 3; i++) {
        turnHor(i, window, -1);
    }
}

bool Cube::isFullCross() {
    if (cubes[1][2][1].colors[5] == cubes[2][2][1].colors[5] and cubes[1][2][1].colors[5] == cubes[0][2][1].colors[5] and cubes[1][2][1].colors[5] == cubes[1][2][2].colors[5] and cubes[1][2][1].colors[5] == cubes[1][2][0].colors[5]) {
        if (cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) {
            return true;
        }
    }
    return false;
}


void Cube::turnHorizontal(int verge, int direction) {
    Colors tempColorsRed[3][3][3];
    Colors tempColorsOrange[3][3][3];
    Colors tempColorsBlue[3][3][3];
    Colors tempColorsGreen[3][3][3];

    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsRed[x][verge][0].colors[i] = cubes[x][verge][0].colors[i];
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsOrange[x][verge][2].colors[i] = cubes[x][verge][2].colors[i];
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsBlue[2][verge][x].colors[i] = cubes[2][verge][x].colors[i];
        }
    }
    for (int z = 0; z <= 2; ++z) {
        for (int i = 0; i < 6; ++i) {
            tempColorsGreen[0][verge][z].colors[i] = cubes[0][verge][z].colors[i];
        }
    }
    if (direction == 1) {
        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2][verge][x].colors[i] = tempColorsRed[x][verge][0].colors[i];
            }
        }
        turnLeft(2, verge, 0);
        turnLeft(2, verge, 1);
        turnLeft(2, verge, 2);
        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2 - x][verge][2].colors[i] = tempColorsBlue[2][verge][x].colors[i];
            }
        }
        turnLeft(0, verge, 2);
        turnLeft(1, verge, 2);
        turnLeft(2, verge, 2);
        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[0][verge][x].colors[i] = tempColorsOrange[x][verge][2].colors[i];
            }
        }
        turnLeft(0, verge, 0);
        turnLeft(0, verge, 1);
        turnLeft(0, verge, 2);
        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2 - x][verge][0].colors[i] = tempColorsGreen[0][verge][x].colors[i];
            }
        }
        turnLeft(0, verge, 0);
        turnLeft(1, verge, 0);
        turnLeft(2, verge, 0);
    } else {
        for (int i = 0; i < 3; ++i) {
            turnHorizontal(verge, 1);
        }
    }
}
void Cube::turnHor(int verge, GLFWwindow* window, int direction) {
    float turnSpeed = 7.0f;
    float totalAngle = 0.0f;
    glm::vec3 center = glm::vec3(1.0f, verge * 2.0f + 1.0f, 1.0f);

    while (90.0f >= totalAngle) {
        totalAngle += turnSpeed;

        for (int x = 0; x < 3; x++) {
            for (int z = 0; z < 3; z++) {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), center);
                model = glm::rotate(model, glm::radians(turnSpeed), glm::vec3(0, -1*direction, 0));
                model = glm::translate(model, -center);
                cubes[x][verge][z].modelMatrix = model * cubes[x][verge][z].modelMatrix;
            }
        }
        drawScene();
        glfwSwapBuffers(window);
    }

    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cubes[x][verge][z].modelMatrix = glm::mat4(1.0f);
        }
    }

    turnHorizontal(verge, direction);
    drawScene();
    glfwSwapBuffers(window);
}
void Cube::turnVer(int verge, GLFWwindow* window, int direction) {
    float turnSpeed = 7.0f;
    float totalAngle = 0.0f;

    glm::vec3 center = glm::vec3(verge * 2.0f + 1.0f, 1.0f, 1.0f);

    while (90.0f >= totalAngle) {
        totalAngle += turnSpeed;

        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), center);
                model = glm::rotate(model, glm::radians(turnSpeed), glm::vec3(1*direction, 0, 0));
                model = glm::translate(model, -center);

                cubes[verge][y][z].modelMatrix = model * cubes[verge][y][z].modelMatrix;
            }
        }
        drawScene();
        glfwSwapBuffers(window);
    }

    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            cubes[verge][y][z].modelMatrix = glm::mat4(1.0f);
        }
    }

    turnVertical(verge, direction);
    drawScene();
    glfwSwapBuffers(window);
}
void Cube::turnToTheSide(int verge, int direction) {
    Colors tempColorsBlue[3][3][3];
    Colors tempColorsGreen[3][3][3];
    Colors tempColorsWhite[3][3][3];
    Colors tempColorsYellow[3][3][3];

    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsBlue[2][x][verge].colors[i] = cubes[2][x][verge].colors[i];
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsYellow[x][2][verge].colors[i] = cubes[x][2][verge].colors[i];
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsGreen[0][x][verge].colors[i] = cubes[0][x][verge].colors[i];
        }
    }
    for (int x = 0; x < 3; ++x) {
        for (int i = 0; i < 6; ++i) {
            tempColorsWhite[x][0][verge].colors[i] = cubes[x][0][verge].colors[i];
        }
    }
    if (direction == 1) {
        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2 - x][2][verge].colors[i] = tempColorsBlue[2][x][verge].colors[i];
            }
        }
        turnUpFace(0, 2, verge);
        turnUpFace(1, 2, verge);
        turnUpFace(2, 2, verge);

        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[0][x][verge].colors[i] = tempColorsYellow[x][2][verge].colors[i];
            }
        }

        turnUpFace(0, 0, verge);
        turnUpFace(0, 1, verge);
        turnUpFace(0, 2, verge);

        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2 - x][0][verge].colors[i] = tempColorsGreen[0][x][verge].colors[i];
            }
        }
        turnUpFace(0, 0, verge);
        turnUpFace(1, 0, verge);
        turnUpFace(2, 0, verge);

        for (int x = 0; x < 3; ++x) {
            for (int i = 0; i < 6; ++i) {
                cubes[2][x][verge].colors[i] = tempColorsWhite[x][0][verge].colors[i];
            }
        }
        turnUpFace(2, 0, verge);
        turnUpFace(2, 1, verge);
        turnUpFace(2, 2, verge);
    } else {
        for (int i = 0; i < 3; ++i) {
            turnToTheSide(verge, 1);
        }
    }
}
void Cube::turnSide(int verge, GLFWwindow* window, int direction) {
    float turnSpeed = 7.0f;
    float totalAngle = 0.0f;

    glm::vec3 center = glm::vec3(1.0f, 1.0f, verge * 2.0f + 1.0f);

    while (90.0f >= totalAngle) {
        totalAngle += turnSpeed;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), center);
                model = glm::rotate(model, glm::radians(turnSpeed), glm::vec3(0, 0, 1*direction));
                model = glm::translate(model, -center);

                cubes[x][y][verge].modelMatrix = model * cubes[x][y][verge].modelMatrix;
            }
        }
        drawScene();
        glfwSwapBuffers(window);
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cubes[x][y][verge].modelMatrix = glm::mat4(1.0f);
        }
    }

    turnToTheSide(verge, direction);
    drawScene();
    glfwSwapBuffers(window);
}

void Cube::solveCross(GLFWwindow* window) {
    int k = 0;
    while (!isCross()) {
        if (cubes[1][0][0].colors[4] == cubes[1][2][1].colors[5]) {
            if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                F2(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                F2(window);
            } else if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                F2(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                U2(window);
                F2(window);
            }
        }
        if (cubes[1][0][2].colors[4] == cubes[1][2][1].colors[5]) {
            if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U2(window);
                F2(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                F2(window);
            } else if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                turnSide(2, window, 1);
                turnSide(2, window, 1);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                turnSide(2, window, 1);
                turnSide(2, window, 1);
            }
        }
        if (cubes[0][0][1].colors[4] == cubes[1][2][1].colors[5]) {
            if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                R2(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                U1(window);
                R2(window);
            } else if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                R2(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                R2(window);
            }
        }
        if (cubes[2][0][1].colors[4] == cubes[1][2][1].colors[5]) {
            if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                L1(window);
                L1(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                L1(window);
                L1(window);
            } else if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U2(window);
                L1(window);
                L1(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                L1(window);
                L1(window);
            }
        }

        if (cubes[0][1][0].colors[0] == cubes[1][2][1].colors[5]) {
            if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                R(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                U1(window);
                R(window);
            } else if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                R(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                R(window);
            }
        }
        if (cubes[2][1][0].colors[0] == cubes[1][2][1].colors[5]) {
            if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                L1(window);
            } else if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U2(window);
                L1(window);
            } else if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                L1(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                U1(window);
                L1(window);
            }
        }
        if (cubes[1][2][0].colors[0] == cubes[1][2][1].colors[5]) {
            if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                F(window);
                R(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                F(window);
                U1(window);
                U1(window);
                R(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                F(window);
                U(window);
                R(window);
            } else if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                F1(window);
                U(window);
                L1(window);
            }
        }
        if (cubes[1][0][0].colors[0] == cubes[1][2][1].colors[5]) {
            if (cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                F1(window);
                R(window);
            } else if (cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                F1(window);
                U1(window);
                U1(window);
                R(window);
            } else if (cubes[1][2][0].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                F1(window);
                U1(window);
                U1(window);
                L1(window);
            } else if (cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5]) {
                F1(window);
                U(window);
                R(window);
            }
        }

        changeSide(window);
    }
    while (!(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) and !(cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) and !(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2]) and !(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) and !(cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) and !(cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1])) {
        U(window);
    }

    while (!isFullCross()) {
        if ((cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) or (cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3])){
            pifpaf1(window);
            while (!(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and
                     cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) and
                   !(cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and
                     cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) and
                   !(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and
                     cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2]) and
                   !(cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and
                     cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) and
                   !(cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3] and
                     cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) and
                   !(cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and
                     cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1])) {
                U(window);
            }

        } else if (cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and
                   cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2]) {

            turnSide(2, window, 1);
            U(window);
            turnSide(2, window, -1);
            U1(window);
            turnSide(2, window, 1);

        } else if (cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3]) {
            pifpaf1(window);
        } else if (cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) {
            F(window);
            U(window);
            F1(window);
            U1(window);
            F(window);
        } else if (cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1]) {
            L1(window);
            U(window);
            L(window);
            U1(window);
            L1(window);
        }
    }
}

bool Cube::checkFirstLevel() {
    if (cubes[1][0][1].colors[4] == cubes[2][0][0].colors[4] and cubes[2][0][2].colors[4] == cubes[1][0][1].colors[4] and cubes[0][0][0].colors[4] == cubes[1][0][1].colors[4] and cubes[0][0][2].colors[4] == cubes[1][0][1].colors[4]) {
        return true;
    }
    return false;
}

void Cube::buildFirstLevel(GLFWwindow* window) {
    int co = 0;
    while (!checkFirstLevel()) {
        for (int k = 0; k < 15; ++k) {
            co++;
            if (cubes[0][2][0].colors[0] == cubes[1][0][1].colors[4]) {
                if (cubes[0][2][0].colors[2] == cubes[0][1][1].colors[2] and cubes[0][2][0].colors[5] == cubes[1][1][0].colors[0]) {
                    PifPaf(window);
                    PifPaf(window);
                    PifPaf(window);
                    PifPaf(window);
                    PifPaf(window);
                }
            } else if (cubes[0][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[0][2][0].colors[2] == cubes[1][0][1].colors[4] and cubes[0][2][0].colors[5] == cubes[0][1][1].colors[2]) {
                PifPaf(window);
            } else if (cubes[0][2][0].colors[0] == cubes[0][1][1].colors[2] and cubes[0][2][0].colors[5] == cubes[1][0][1].colors[4] and cubes[0][2][0].colors[2] == cubes[1][1][0].colors[0]) {
                PifPaf(window);
                PifPaf(window);
                PifPaf(window);
            } else if ((cubes[0][0][0].colors[0] == cubes[1][0][1].colors[4] and cubes[0][0][0].colors[2] == cubes[1][1][0].colors[0]) or (cubes[0][0][0].colors[0] == cubes[0][1][1].colors[2] and cubes[0][0][0].colors[2] == cubes[1][0][1].colors[4]) or (cubes[0][0][0].colors[4] == cubes[1][0][1].colors[4] and cubes[0][0][0].colors[2] != cubes[0][1][1].colors[2] and cubes[0][0][0].colors[0] != cubes[1][1][0].colors[0])) {
                PifPaf(window);
            } else if (cubes[0][0][0].colors[0] == cubes[1][0][1].colors[4] or cubes[0][0][0].colors[2] == cubes[1][0][1].colors[4]) {
                PifPaf(window);
            }
            else if (cubes[0][2][2].colors[2] == cubes[1][0][1].colors[4] and cubes[0][2][2].colors[1] == cubes[1][1][2].colors[1] and cubes[0][2][2].colors[5] == cubes[0][1][1].colors[2]) {
                PifPafGreen(window);
                PifPafGreen(window);
                PifPafGreen(window);
                PifPafGreen(window);
                PifPafGreen(window);
            } else if (cubes[0][2][2].colors[2] == cubes[0][1][1].colors[2] and cubes[0][2][2].colors[1] == cubes[1][0][1].colors[4] and cubes[0][2][2].colors[5] == cubes[1][1][2].colors[1]) {
                PifPafGreen(window);
            } else if (cubes[0][2][2].colors[2] == cubes[1][1][2].colors[1] and cubes[0][2][2].colors[1] == cubes[0][1][1].colors[2] and cubes[0][2][2].colors[5] == cubes[1][0][1].colors[4]) {
                PifPafGreen(window);
                PifPafGreen(window);
                PifPafGreen(window);
            } else if ((cubes[0][0][2].colors[2] == cubes[1][0][1].colors[4] and cubes[0][0][2].colors[1] == cubes[0][1][1].colors[2]) or (cubes[0][0][2].colors[2] == cubes[1][1][2].colors[1] and cubes[0][0][2].colors[1] == cubes[1][0][1].colors[4]) or (cubes[0][0][2].colors[4] == cubes[1][0][1].colors[4] and cubes[0][0][2].colors[1] != cubes[1][1][2].colors[1] and cubes[0][0][2].colors[2] != cubes[0][1][1].colors[2])) {
                PifPafGreen(window);
            } else if (cubes[2][2][2].colors[1] == cubes[1][0][1].colors[4] and cubes[2][2][2].colors[3] == cubes[2][1][1].colors[3] and cubes[2][2][2].colors[5] == cubes[1][1][2].colors[1]) {
                PifPafOrange(window);
                PifPafOrange(window);
                PifPafOrange(window);
                PifPafOrange(window);
                PifPafOrange(window);
            } else if (cubes[2][2][2].colors[1] == cubes[1][2][2].colors[1] and cubes[2][2][2].colors[3] == cubes[1][0][1].colors[4] and cubes[2][2][2].colors[5] == cubes[2][1][1].colors[3]) {
                PifPafOrange(window);
            } else if (cubes[2][2][2].colors[1] == cubes[2][1][1].colors[3] and cubes[2][2][2].colors[3] == cubes[1][1][2].colors[1] and cubes[2][2][2].colors[5] == cubes[1][0][1].colors[4]) {
                PifPafOrange(window);
                PifPafOrange(window);
                PifPafOrange(window);
            } else if ((cubes[2][0][2].colors[1] == cubes[1][0][1].colors[4] and cubes[2][0][2].colors[3] == cubes[1][1][2].colors[1]) or (cubes[2][0][2].colors[1] == cubes[2][1][1].colors[3] and cubes[2][0][2].colors[3] == cubes[1][0][1].colors[4]) or (cubes[2][0][2].colors[4] == cubes[1][0][1].colors[4] and cubes[2][0][2].colors[3] != cubes[2][1][1].colors[3] and cubes[2][0][2].colors[1] != cubes[1][1][2].colors[1])) {
                PifPafOrange(window);
            } else if (cubes[2][0][2].colors[1] == cubes[1][0][1].colors[4] or cubes[2][0][2].colors[3] == cubes[1][0][1].colors[4]) {
                PifPafOrange(window);
            }
            else if (cubes[2][2][0].colors[3] == cubes[1][0][1].colors[4] and cubes[2][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][2][0].colors[5] == cubes[2][1][1].colors[3]) {
                PifPafBlue(window);
                PifPafBlue(window);
                PifPafBlue(window);
                PifPafBlue(window);
                PifPafBlue(window);
            } else if (cubes[2][2][0].colors[3] == cubes[2][1][1].colors[3] and cubes[2][2][0].colors[0] == cubes[1][0][1].colors[4] and cubes[2][2][0].colors[5] == cubes[1][1][0].colors[0]) {
                PifPafBlue(window);
            } else if (cubes[2][2][0].colors[3] == cubes[1][1][0].colors[0] and cubes[2][2][0].colors[0] == cubes[2][1][1].colors[3] and cubes[2][2][0].colors[5] == cubes[1][0][1].colors[4]) {
                PifPafBlue(window);
                PifPafBlue(window);
                PifPafBlue(window);
            } else if ((cubes[2][0][0].colors[3] == cubes[1][0][1].colors[4] and cubes[2][0][0].colors[0] == cubes[2][1][1].colors[3]) or (cubes[2][0][0].colors[3] == cubes[1][1][0].colors[0] and cubes[2][0][0].colors[0] == cubes[1][0][1].colors[4]) or (cubes[2][0][0].colors[4] == cubes[1][0][1].colors[4] and cubes[2][0][0].colors[0] != cubes[1][1][0].colors[0] and cubes[2][0][0].colors[3] != cubes[2][1][1].colors[3])) {
                PifPafBlue(window);
            } else if (cubes[2][0][0].colors[3] == cubes[1][0][1].colors[4] or cubes[2][0][0].colors[0] == cubes[1][0][1].colors[4]) {
                PifPafBlue(window);
            } else {
                turnHor(0, window, -1);
                turnHor(1, window, -1);
            } if (k <= 5) {
                U(window);
            } else {
                changeSide(window);
            }
            if (checkFirstLevel()) {
                break;
            }
        }

    }
}

bool Cube::checkSecondLevel() {
    if (cubes[0][1][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][1][0].colors[0] == cubes[1][1][0].colors[0] and cubes[0][1][2].colors[1] == cubes[1][1][2].colors[1] and cubes[2][1][2].colors[1] == cubes[1][1][2].colors[1] and cubes[0][1][0].colors[2] == cubes[0][1][1].colors[2] and cubes[0][1][2].colors[2] == cubes[0][1][1].colors[2] and cubes[2][1][2].colors[3] == cubes[2][1][1].colors[3] and cubes[2][1][0].colors[3] == cubes[2][1][1].colors[3]) {
        return true;
    }
    return false;
}

void Cube::buildSecondLevel(GLFWwindow* window) {
    int co = 0;
    int count = 0;
    while (!checkSecondLevel()) {
        for (int k = 0; k < 30; ++k) {
            co++;
            if ((cubes[0][1][0].colors[0] != cubes[1][1][0].colors[0] or cubes[0][1][0].colors[2] != cubes[0][1][1].colors[2]) and cubes[0][1][0].colors[0] != cubes[1][2][1].colors[5] and cubes[0][1][0].colors[2] != cubes[1][2][1].colors[5]) {
                sunflower_r(window);
                U1(window);
                std::cout << 99;
                while (cubes[1][1][0].colors[0] != cubes[1][2][0].colors[0]) {
                    turnHor(0, window, -1);
                    turnHor(1, window, -1);
                }
                if (cubes[1][2][0].colors[5] == cubes[2][1][1].colors[3]) {
                    sunflower_l(window);
                } else {
                    sunflower_r(window);
                }
            } else if (cubes[1][1][0].colors[0] == cubes[1][2][0].colors[0] and cubes[1][2][0].colors[5] == cubes[0][1][1].colors[2]) {
                sunflower_r(window);
            }  else if (cubes[1][1][0].colors[0] == cubes[1][2][0].colors[0] and cubes[1][2][0].colors[5] == cubes[2][1][1].colors[3]) {
                sunflower_l(window);
            } else {
                U(window);
                count++;
                if (count == 4) {
                    changeSide(window);
                    count = 0;
                }
            }
            if (checkSecondLevel()) {
                break;
            }
        }
    }
}

void Cube::buildYellowCross(GLFWwindow* window) {
    int ci = 0;
    while (!isCross()) {
        for (int k = 0; k < 50; ++k) {
            if (cubes[1][2][0].colors[5] == cubes[1][2][1].colors[5] and
                cubes[1][2][2].colors[5] == cubes[1][2][1].colors[5] and
                cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5] and
                cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                F(window);
                PifPaf(window);
                F1(window);
            } else if (cubes[1][2][0].colors[5] == cubes[1][2][1].colors[5] and
                       cubes[2][2][1].colors[5] == cubes[1][2][1].colors[5] and
                       cubes[1][2][2].colors[5] != cubes[1][2][1].colors[5] and
                       cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                U(window);
                F(window);
                PifPaf(window);
                PifPaf(window);
                F1(window);
            } else if (cubes[1][2][1].colors[5] != cubes[1][2][2].colors[5] and cubes[1][2][1].colors[5] != cubes[1][2][0].colors[5] and cubes[2][2][1].colors[5] != cubes[1][2][1].colors[5] and cubes[0][2][1].colors[5] != cubes[1][2][1].colors[5]) {
                F(window);
                PifPaf(window);
                F1(window);
                U2(window);
                F(window);
                PifPaf(window);
                PifPaf(window);
                F1(window);
            } else {
                changeSide(window);
            }

            if (isCross()) {
                break;
            }
        }
    }
}

bool Cube::checkEdges(GLFWwindow* window) {
    for (int i = 0; i < 4; ++i) {
        if (cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3] and cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2] and cubes[1][1][2].colors[1] == cubes[1][2][2].colors[1]) {
            return true;
        }
        U(window);
    }
    return false;
}

void Cube::buildEdges(GLFWwindow* window) {
    int co = 0;
    while (!checkEdges(window)) {
        for (int i = 0; i < 50; ++i) {
            co++;
            if ((cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[1][1][2].colors[1] == cubes[1][2][2].colors[1] and cubes[2][2][1].colors[3] != cubes[2][1][1].colors[3] and cubes[0][2][1].colors[2] != cubes[0][1][1].colors[2]) or (cubes[1][2][0].colors[0] != cubes[1][1][0].colors[0] and cubes[1][1][2].colors[1] != cubes[1][2][2].colors[1] and cubes[2][2][1].colors[3] == cubes[2][1][1].colors[3] and cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2])) {
                R(window);
                U(window);
                R1(window);
                F1(window);
                PifPaf(window);
                R1(window);
                F(window);
                R(window);
                R(window);
                U1(window);
                R1(window);
                U1(window);
            }
            else if ((cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[0][2][1].colors[2] == cubes[0][1][1].colors[2])) {
                change(window);
                change(window);
                R(window);
                U(window);
                R1(window);
                F1(window);
                PifPaf(window);
                R1(window);
                F(window);
                R2(window);
                U1(window);
                R1(window);
                U1(window);
            } else if (cubes[1][2][0].colors[0] == cubes[1][1][0].colors[0] and cubes[2][1][1].colors[3] == cubes[2][2][1].colors[3]) {
                change(window);
                R(window);
                U(window);
                R1(window);
                F1(window);
                PifPaf(window);
                R1(window);
                F(window);
                R2(window);
                U1(window);
                R1(window);
                U1(window);
            } else if (cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1] and cubes[2][1][1].colors[3] == cubes[2][2][1].colors[3]) {
                R(window);
                U(window);
                R1(window);
                F1(window);
                PifPaf(window);
                R1(window);
                F(window);
                R2(window);
                U1(window);
                R1(window);
                U1(window);
            }  else if (cubes[1][2][2].colors[1] == cubes[1][1][2].colors[1] and cubes[0][1][1].colors[2] == cubes[0][2][1].colors[2]) {
                changeSide(window);
                R(window);
                U(window);
                R1(window);
                F1(window);
                PifPaf(window);
                R1(window);
                F(window);
                R2(window);
                U1(window);
                R1(window);
                U1(window);
            } else {
                U(window);
            }
            if (checkEdges(window)) {
                break;
            }
        }
        if (co == 0) {
            break;
        }
    }
}

bool Cube::checkUpCross() {
    if (cubes[2][1][1].colors[3] == cubes[2][2][0].colors[3] and cubes[2][1][1].colors[3] == cubes[2][0][0].colors[3] and cubes[2][1][1].colors[3] == cubes[2][0][2].colors[3] and cubes[2][1][1].colors[3] == cubes[2][2][2].colors[3]) {
        return true;
    }
    return false;
}

void Cube::buildUpCross(GLFWwindow* window) {
    int co = 0;
    F1(window);
    turnSide(1, window, -1);
    turnSide(2, window, -1);
    while (!checkUpCross()) {
        if (cubes[2][2][2].colors[5] == cubes[2][1][1].colors[3]) {
            PifPaf(window);
            PifPaf(window);
            PifPaf(window);
            PifPaf(window);
        } else if (cubes[2][2][2].colors[1] == cubes[2][1][1].colors[3]) {
            PifPaf(window);
            PifPaf(window);
        } else {
            L1(window);
        }
    }
    F(window);
    turnSide(1, window, 1);
    turnSide(2, window, 1);
}

bool Cube::checkFullCube() {
    if (cubes[2][2][0].colors[5] == cubes[1][2][1].colors[5] and cubes[2][2][2].colors[5] == cubes[1][2][1].colors[5]) {
        return true;
    }
    return false;
}

void Cube::solve(GLFWwindow* window) {
    for (int i = 0; i < 4; ++i) {
        if (cubes[0][2][0].colors[5] == cubes[1][1][0].colors[0] and
            cubes[0][2][0].colors[2] == cubes[0][1][1].colors[2]) {
            break;
        }
        changeSide(window);
    }
    F1(window);
    turnSide(1, window, -1);
    turnSide(2, window, -1);
    while (!checkFullCube()) {
        if (cubes[2][2][2].colors[5] == cubes[1][2][1].colors[5] or
            cubes[2][0][2].colors[1] == cubes[1][1][2].colors[1] or
            cubes[2][0][0].colors[0] == cubes[1][1][0].colors[0] or
            cubes[2][2][0].colors[0] == cubes[1][1][0].colors[0]) {
            while (cubes[2][0][2].colors[1] != cubes[1][1][2].colors[1]) {
                std::cout << 1;
                R(window);
                turnVer(1, window, 1);
                L1(window);
            }
            Infarct(window);
        } else {
            Infarct(window);
        }
    }
}