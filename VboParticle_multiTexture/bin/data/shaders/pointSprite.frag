#version 120

uniform sampler2D tex1;
uniform sampler2D tex2;
varying float textureNumber;

void main() {
   
    vec2 st = gl_TexCoord[0].st;
    
    vec4 color = vec4(0);
    
    if(textureNumber == 0)color = texture2D(tex1,st);
    else color = texture2D(tex2,st);
    
    gl_FragColor =  color * gl_Color;
    
}

