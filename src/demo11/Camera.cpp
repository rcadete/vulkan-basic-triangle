#include <glm/glm.hpp>

using glm::vec3;

class Camera {
public:
    vec3 position;
    Camera() {
        position = vec3(0,0,0);
    }
};
