#version 410

in vec2 fragmentUV;
uniform sampler2D parrotTexture; // 텍스처는 셰이더에서 변하는 값이 아니기 때문에 유니폼을 사용한다
uniform sampler2D checkerTexture;
uniform float brightness;
uniform vec4 tintMultifly;
uniform vec4 brightnessAdd;

out vec4 outColor;

// multifly vs add
// 일반적으로 색조 변경은 multifly (원본 색상 비율 유지)
// 밝기 변경은 add (균일하게 빛나는 효과)

void main()
{
	// outColor = vec4(fragmentUV, 0.0f, 1.0f); // UV 좌표를 디버그하기 위한 용도
	// vec4 texturColor = texture(parrotTexture, fragmentUV) * tintMultifly + brightnessAdd; // 곱셈 연산 후 덧셈 연산하여 연산 최적화
	// texturColor.rgb = texturColor.rgb + brightness; // rgb 채널에 float를 곱해주어 밝기를 조절하는 방법
	vec4 parrotColor = texture(parrotTexture, fragmentUV);
	vec4 checkerColor = texture(checkerTexture, fragmentUV);
	// outColor = mix(parrotColor, checkerColor, 0.5f);
	outColor = mix(checkerColor, parrotColor, checkerColor.r);
}
