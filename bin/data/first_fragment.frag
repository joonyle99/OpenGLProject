#version 410
in vec4 fragmentColor; // vs에서의 변수와 네이밍이 같아야 한다
uniform vec4 fragmentColor2; // 유니폼 변수라서 프레그먼트 보간을 거치지 않으며 서로 다른 렌더 파이프라인 단계에서 공유하는 변수이다
out vec4 outColor; // 한 번에 하나의 프레그먼트(픽셀)를 처리한다

void main()
{
    // outColor = fragmentColor;
    outColor = fragmentColor2;
}
