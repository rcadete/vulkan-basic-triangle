
#ifndef LINE_H
#define LINE_H

#include <vector>
#include <glm/glm.hpp>


class Line {
    int shaderProgram;
    unsigned int VBO, VAO;
    std::vector<float> vertices;
    glm::vec3 startPoint;
    glm::vec3 endPoint;
    glm::mat4 MVP = glm::mat4(1.0);    // model-view-projection
    glm::vec3 lineColor;
public:
    Line();
    Line(glm::vec3 start, glm::vec3 end);
    int setMVP(glm::mat4 mvp);
    int setColor(glm::vec3 color);
    int draw();
    ~Line();
};



#endif //LINE_H
