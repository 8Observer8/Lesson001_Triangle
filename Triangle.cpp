#include "Triangle.h"

Triangle::Triangle( QOpenGLShaderProgram *program,
                    int vertexAttr, int colorAttr) :
    m_program( program ),
    m_vertexAttr( vertexAttr ),
    m_colorAttr( colorAttr )
{
    initVertices();
    initColors();
}

void Triangle::draw()
{
    m_program->setAttributeArray( m_vertexAttr, m_vertices.data(), 3 );
    m_program->setAttributeArray( m_colorAttr, m_colors.data(), 3 );

    m_program->enableAttributeArray( m_vertexAttr );
    m_program->enableAttributeArray( m_colorAttr );

    glDrawArrays( GL_TRIANGLES, 0, m_vertices.size() / 3 );

    m_program->disableAttributeArray( m_vertexAttr );
    m_program->disableAttributeArray( m_colorAttr );
}

void Triangle::initVertices()
{
    m_vertices.resize( 9 );

    // 0
    m_vertices[0] = -0.5f;
    m_vertices[1] = -0.5f;
    m_vertices[2] = 0.0f;

    // 1
    m_vertices[3] = 0.5f;
    m_vertices[4] = -0.5f;
    m_vertices[5] = 0.0f;

    // 2
    m_vertices[6] = 0.0f;
    m_vertices[7] = 0.5f;
    m_vertices[8] = 0.0f;
}

void Triangle::initColors()
{
    m_colors.resize( 9 );

    // 0
    m_colors[0] = 1.0f;
    m_colors[1] = 0.0f;
    m_colors[2] = 0.0f;

    // 1
    m_colors[3] = 0.0f;
    m_colors[4] = 1.0f;
    m_colors[5] = 0.0f;

    // 2
    m_colors[6] = 0.0f;
    m_colors[7] = 0.0f;
    m_colors[8] = 1.0f;
}
