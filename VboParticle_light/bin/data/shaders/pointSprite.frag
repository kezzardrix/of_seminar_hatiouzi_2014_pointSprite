#version 120

//based on http://marina.sys.wakayama-u.ac.jp/~tokoi/?date=20110324

uniform sampler2D tex;
varying vec3 light;

void main() {
    
    vec4 color;
    
    color = texture2D(tex, gl_TexCoord[0].xy);
    
    vec3 n;
    n.xy = gl_TexCoord[0].xy * 2.0 - 1.0; //[0, 1] → [-1, 1] に変換
    n.z = 1.0 - dot(n.xy, n.xy); //xyの二乗和を引く
    if (n.z < 0.0) discard; //負の値なら捨てる
    
    n.z = sqrt(n.z); //球面だと仮定して法線を求める
    
    vec3 m = normalize(gl_NormalMatrix * n); //法線を視点座標に変換
    float d = dot(light, m); 
    float s = pow(clamp(-reflect(light, m).z, 0.0, 1.0), 20.0); //拡散反射光強度
    vec3 spec = vec3(mix(d, s, 1.0)); // 鏡面反射光強度
    
    gl_FragColor = color * gl_Color + vec4(spec.rgb,0.0);
    
}

