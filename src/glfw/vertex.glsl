#version 120

attribute vec3 aPos;
attribute vec2 aTexCoord;
varying vec2 fragCoord;

void main() {
    gl_Position = vec4(aPos, 1.0);
    // Pass UV coordinates directly
    fragCoord = aTexCoord;
}
