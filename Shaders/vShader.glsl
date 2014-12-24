attribute highp vec4 vertexAttr;
uniform mediump mat4 matrix;
attribute lowp vec4 colorAttr;
varying lowp vec4 color;

void main()
{
    gl_Position = matrix * vertexAttr;
    color = colorAttr;
}
