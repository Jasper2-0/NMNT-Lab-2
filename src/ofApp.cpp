#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    ofSetFrameRate(60);
    
#ifdef TARGET_OPENGLES
    shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
#endif
    
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.hasWaitingMessages()) {
        handleOSC();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofHideCursor();
    shader.begin();
    
    /*
     * move my OSC inputs into the shader
     */
    shader.setUniform1f("c0", c0);
    shader.setUniform1f("c1", c1);
    shader.setUniform1f("c2", c2);
    shader.setUniform1f("c3", c3);
    shader.setUniform1f("c4", c4);
    shader.setUniform1f("c5", c5);
    shader.setUniform1f("c6", c6);
    shader.setUniform1f("c7", c7);
    shader.setUniform1f("c8", c8);
    shader.setUniform1f("c9", c9);
    shader.setUniform1f("c10", c10);
    shader.setUniform1f("c11", c11);
    shader.setUniform1f("c12", c12);
    shader.setUniform1f("c13", c13);
    shader.setUniform1f("c14", c14);
    shader.setUniform1f("c15", c15);
    
    /*
     * get the OF time into the shader
     */
    shader.setUniform1f("ofTime", ofGetElapsedTimef());
    
    /*
     * get the screenResolution into the shader
     */
    shader.setUniform2f("ofResolution",ofGetWidth(),ofGetHeight());
    
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();

}

//--------------------------------------------------------------
void ofApp::handleOSC() {
    ofxOscMessage m;
    receiver.getNextMessage(m);
    cout << m.getArgAsFloat(0) << "\n";
    
    /*
     * Yes, I'm a aware that this is a ton of copy-paste. it gets the job done though ^_^
     */
    
    if (m.getAddress() == "/midi/cc21/9") {
        c0 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc22/9") {
        c1 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc23/9") {
        c2 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc24/9") {
        c3 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc25/9") {
        c4 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc26/9") {
        c5 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc27/9") {
        c6 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc28/9") {
        c7 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc41/9") {
        c8 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc42/9") {
        c9 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc43/9") {
        c10 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc44/9") {
        c11 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc45/9") {
        c12 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc46/9") {
        c13 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc47/9") {
        c14 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc48/9") {
        c15 = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/midi/cc48/9") {
        c15 = m.getArgAsFloat(0);
    }    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }

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
