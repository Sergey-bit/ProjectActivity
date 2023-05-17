#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 iResolution
uniform float iPercent;
uniform vec3 iColor;

void main(void)
{
    vec2 width = gl_FragCoord.x / iResolution.x;
    if (uv <= iPercent)
    {
        gl_FragColor = vec4(iColor * clamp(iPercent + 0.1f, 0.f, 1.f), 1.0f);
    }
}