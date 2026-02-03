#version 410
layout ( location = 0) in vec3 pos; // 한 번에 하나의 버텍스를 처리한다
layout ( location = 1) in vec4 color;

out vec4 fragmentColor;

void main()
{
    // screen to ndc
    // float x = (position.x / 1024.0) * 2.0 - 1.0;
    // float y = (position.y / 768.0) * 2.0 - 1.0;
    // gl_Position = vec4(x, y, 0.0, 1.0);

    // ndc
	gl_Position = vec4(pos, 1.0); // 기본적으로 출력되는 변수

    // 프레그먼트 셰이더로 전달된다
    fragmentColor = color; // 새롭게 선언되어 출력되는 변수
}