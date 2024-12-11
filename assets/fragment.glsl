#version 300 es
precision highp float;

uniform vec2 iResolution;
uniform int jsButtonCount;
uniform int jsButtonValues[20];

in vec2 fragCoord;
out vec4 fragColor;

const vec3 BLACK = vec3(0);
const vec3 RED = vec3(1.0, 0.0, 0.0);
const vec3 BLUE = vec3(0.0, 0.0, 1.0);

float circle(vec2 uv, vec2 pos, float radius, float smoothWidth) {
  float d = length(uv - pos);
  return smoothstep(radius + smoothWidth, radius - smoothWidth, d);
}

void main() {
  vec2 uv = fragCoord/iResolution.xy;
  vec2 center = uv;
  center.x *= iResolution.x/iResolution.y;

  vec3 color = BLACK;
  for (int i=0; i<jsButtonCount; i++) {
    float c = circle(center, vec2(0.05 + float(i) * 0.1, 1.0 - 0.04), 0.04, 0.01);
    if (jsButtonValues[i] == 0){
      color += c * BLUE;
    } else {
      color += c * RED;
    }
  }
  fragColor = vec4(color, 1.0);
}
