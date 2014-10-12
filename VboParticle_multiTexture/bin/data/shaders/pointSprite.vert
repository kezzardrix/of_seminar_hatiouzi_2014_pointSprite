#version 120

varying float textureNumber;

void main() {
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_FrontColor = gl_Color;
    
    gl_PointSize = gl_Normal.x;
    textureNumber = gl_Normal.y;
    
}

