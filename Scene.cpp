#include <QMatrix4x4>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent )
{

}

Scene::~Scene()
{
    delete m_triangle;
}

void Scene::initializeGL()
{
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );
    if ( !m_program.link() )
    {
        qWarning( "Error: unable to link a shader program." );
        return;
    }

    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    m_colorAttr = m_program.attributeLocation( "colorAttr" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );

    m_triangle = new Triangle( &m_program, m_vertexAttr, m_colorAttr );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( -2.0f, 2.0f, -2.0f, 2.0f, 2.0f, -2.0f );
    matrix.translate( 0.0f, 0.0f, -1.0f );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_triangle->draw();

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}
