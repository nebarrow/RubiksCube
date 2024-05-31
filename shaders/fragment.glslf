#version 330 core
out vec4 FragColor;

uniform vec3 sideColors;

void main()
{
    FragColor = vec4(sideColors, 1.0);
}
