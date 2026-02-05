#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// screen
	//triangle.addVertex(glm::vec3(0.0, 0.0, 0.0));
	//triangle.addVertex(glm::vec3(0.0, 768.0, 0.0));
	//triangle.addVertex(glm::vec3(1024.0, 768.0, 0.0));

	// ndc (normal device coordinates)
	//triangle.addVertex(glm::vec3(-1.0f, 1.0f, 0.0f));
	//triangle.addVertex(glm::vec3(-1.0f, -1.0f, 0.0f));
	//triangle.addVertex(glm::vec3(1.0f, -1.0f, 0.0f));
	//triangle.addColor(ofFloatColor(1.0f, 0.0f, 0.0f, 1.0f)); // r
	//triangle.addColor(ofFloatColor(0.0f, 1.0f, 0.0f, 1.0f)); // g
	//triangle.addColor(ofFloatColor(0.0f, 0.0f, 1.0f, 1.0f)); // b

	quad.addVertex(glm::vec3(-1, 1, 0)); // lt - NDC 좌표계 고려
	quad.addVertex(glm::vec3(-1, -1, 0)); // lb
	quad.addVertex(glm::vec3(1, -1, 0)); // rb
	quad.addVertex(glm::vec3(1, 1, 0)); // rt
	quad.addColor(ofFloatColor(1, 0, 0, 1)); // r
	quad.addColor(ofFloatColor(0, 1, 0, 1)); // g
	quad.addColor(ofFloatColor(0, 0, 1, 1)); // b
	quad.addColor(ofFloatColor(1, 1, 1, 1)); // w

	// vertex에 텍스처의 uv좌표 데이터를 입력한다
	quad.addTexCoord(glm::vec2(0, 1)); // g - lt - UV 좌표계 고려
	quad.addTexCoord(glm::vec2(0, 0)); // black - lb
	quad.addTexCoord(glm::vec2(1, 0)); // r - rb
	quad.addTexCoord(glm::vec2(1, 1)); // y - rt

	// index buffer - 버텍스가 삼각형을 구성하는 순서를 담은 데이터 구조
	ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0 };
	quad.addIndices(indices, 6);

	shader.load("texture_vertex.vert", "texture_fragment.frag");

	ofDisableArbTex(); // legacy - pixel 좌표 사용 기능 off / uv 좌표 사용 기능 on

	image1.load("parrot.png");
	image1.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT); // 텍스처 샘플링 시 uv 0-1이 아닌 좌표에서 대처하는 방식 설정
	
	image2.load("checker.jpg");
	image2.getTexture().setTextureWrap(GL_REPEAT, GL_REPEAT);

	 ofDisableAlphaBlending(); // 알파 블랜딩을 비활성화해서 rgb 말고 a 채널에도 밝기를 곱해주어도 적용 안되도록 한다
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();
	//shader.setUniform4f("fragmentColor2", glm::vec4(0, 1, 1, 1)); // shader.begin() 뒤에 호출되어야. 대상 셰이더가 지정된다
	//triangle.draw();
	shader.setUniformTexture("parrotTexture", image1, 0);
	shader.setUniformTexture("checkerTexture", image2, 1);
	shader.setUniform1f("time", ofGetElapsedTimef());
	shader.setUniform4f("tintMultifly", glm::vec4(1.0f, 0.5f, 0.5f, 1.0f)); // 빨강 강조
	shader.setUniform4f("brightnessAdd", glm::vec4(0.5f, 0.5f, 0.0f, 0.0f)); // 노랑 발광
	quad.draw();
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// origin: left top (0, 0)
	//glm::vec3 curPos = triangle.getVertex(2);
	//triangle.setVertex(2, curPos + glm::vec3(0, -20, 0));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
