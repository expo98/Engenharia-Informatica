#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//hello world
	std::cout << "Ola mundo CG!!" << endl;
	
	//printa a largura da tela no console
	std::cout << endl << gw();

	//teste de funcoes openGl
	ofSetBackgroundAuto(false);//desabilita automacao de limpeza de janela OF
	glClearColor(0.5, 1., 0.5, 1.);//define uma cor de fundo para janela (Red, Green, Blue, Aplpha)
	
}

//--------------------------------------------------------------
void ofApp::update(){
	//coloca o frameRate da aplica��o como nome da janela
	setFrWt();
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//limpa a janela com a cor definida
	glClear(GL_COLOR_BUFFER_BIT);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
