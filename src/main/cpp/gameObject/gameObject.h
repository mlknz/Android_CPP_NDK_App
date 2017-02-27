#ifndef __GameObject__
#define __GameObject__

#include <string>
#include <GLES2/gl2.h>

#include "../gamestate.h"
#include "../assetManager/assetManager.h"

// abstract class
class GameObject {
public:
    GameObject() {};
    GameObject(GameState* g, AssetManager* a);
    ~GameObject();

    // void render() {};

    std::string type = "GameObject";
    GLuint shaderProgram;
    int zIndex = 0;

protected:
    void setShaderProgram(std::string type);
    GLuint createShaderProgram(std::string type);

private:
    virtual void dispose() = 0;

    GameState* gameState;
    AssetManager* assetManager;

};

#endif