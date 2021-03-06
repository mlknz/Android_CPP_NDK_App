#include "renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../common.h"
#include "../config.h"

Renderer::Renderer(ViewController* viewController) {
    m_viewController = viewController;
    setClearColor(config::clearColor[0], config::clearColor[1], config::clearColor[2], config::clearColor[3]);
    glm::vec2 tstvec; // test
    FT_Library ft; // test
    if (FT_Init_FreeType(&ft)) {
        // throw smth
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Renderer::~Renderer() {
}

void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
    m_viewController->resize(w, h);
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    m_viewController->activeView->draw();
}