#version 410

// location 0 - 위치
// location 1 - 색상
// location 2 - 노말
// location 3 - UV

layout ( location = 0) in vec3 pos;
layout ( location = 3) in vec2 uv;

uniform float time;

out vec2 fragmentUV;

void main()
{
	gl_Position = vec4(pos, 1.0);
	vec2 temp = vec2(uv.x, 1.0 - uv.y); // 수직 방향으로 텍스처 뒤집기
	vec2 temp2 = temp + vec2(1.0, 0.0) * time; // vertex shader에서 UV좌표를 스크롤 시킨다
	fragmentUV = temp2;
}