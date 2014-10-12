#version 120

varying vec3 light;
uniform vec3 lightPos;

void main() {
    
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_FrontColor = gl_Color;
    
    gl_PointSize = gl_Normal.x; //法線の値でポイントサイズを決めちゃう
    
    light = normalize(vec3(lightPos - gl_Vertex.xyz)); //光線ベクトルを求める
    
}

