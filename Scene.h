#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include "Triangle.h"

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    Triangle *m_triangle;
    QOpenGLShaderProgram m_program;

    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;
};

#endif // SCENE_H
