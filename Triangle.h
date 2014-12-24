#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <QOpenGLShaderProgram>

class Triangle
{
public:
    Triangle( QOpenGLShaderProgram *program,
              int vertexAttr, int colorAttr );

    void draw();

private:
    void initVertices();
    void initColors();

    std::vector<float> m_vertices;
    std::vector<float> m_colors;

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_colorAttr;
};

#endif // TRIANGLE_H
