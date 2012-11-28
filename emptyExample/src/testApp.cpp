#include "testApp.h"
#include "Particle.h"

vector<Particle> particles;
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(30);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    sky.loadImage("skyisthelimit.jpg");

}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<particles.size(); i++)
    {
        if(particles[i].getAge() > 5)
        {
            particles.erase(particles.begin()+i);
        }
        else
        {
            particles[i].updateMe();
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //sky
    ofFill();
    ofSetColor(250,250,250);
    sky.draw(0,0);

    
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].drawMe();
    }


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    Particle p;
    p.here(x, y);
    particles.push_back(p);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}