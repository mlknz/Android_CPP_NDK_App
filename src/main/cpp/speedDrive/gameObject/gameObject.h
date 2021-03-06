#ifndef __GameObject__
#define __GameObject__

#include <string>
#include <GLES2/gl2.h>

#include "../gamestate.h"

// abstract class
class GameObject {
public:
    GameObject();
    ~GameObject();

    virtual void render() {};
    virtual void resize() {};
    virtual bool containsTouch(float touchX, float touchY) {return false;}; // params in [0, 1]

    std::string type = "GameObject";
    GLuint shaderProgram;
    int zIndex = 0;

protected:
    void setShaderProgram(std::string type);
    GLuint createShaderProgram(std::string type);

    GameState* m_gameState;
private:
    virtual void dispose() = 0;
};

#endif