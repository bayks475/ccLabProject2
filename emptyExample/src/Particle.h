//
//  Particle.h
//  emptyExample
//
//  Created by Selin Baykal on 11/24/12.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    // -------------------------
    void there()
    {
       
        nPts = (int)ofRandom(2, 4);
        velocity.x = ofRandom(-10, 10);
        velocity.y = ofRandom(-10, 10);
        
        rotation = ofRandom(0, M_TWO_PI);
        rotationSpeed = M_TWO_PI * ofRandom(-1, 1);
        dragging = false;
        born = ofGetElapsedTimef(); 
    }
    
    // -------------------------
    // flower at a particular location
    void here(float x, float y)
    {
        
        nPts = (int)ofRandom(4, 8) * 2.0;
        
        position.x = x;
        position.y = y;
        
        velocity.x = ofRandom(-5, 5);
        velocity.y = ofRandom(-5, 5);
        
        color.r = ofRandom(0, 255);
        color.g = ofRandom(0, 255);
        color.b = ofRandom(0, 255);
        
        rotation = ofRandom(50, M_TWO_PI);
        rotationSpeed = M_TWO_PI * ofRandom(-0.5, 0.5);
        
        dragging = false;
        born = ofGetElapsedTimef(); //when the particle is inited
    }
    
    // -------------------------
    void updateMe()
    {
        if(!dragging)
        {
            position += velocity;
            
            if(position.x > ofGetWidth()+outerRadius) {
                position.x = -outerRadius;
            }
            if(position.x < -outerRadius) {
                position.x = ofGetWidth()+outerRadius;
            }
            if(position.y > ofGetHeight()+outerRadius) {
                position.y = -outerRadius;
            }
            if(position.y < -outerRadius) {
                position.y = ofGetHeight()+outerRadius;
            }
        }
        rotation += rotationSpeed;
    }
    
    // -------------------------
    void drawMe()
    {
        ofEnableAlphaBlending();
        ofPushMatrix();
        ofTranslate(position.x, position.y);
        ofRotate(rotation);
        
        for(int i=0; i<5; i++)
        {
            ofPushMatrix();
            float scale = ofMap(i, 0, 2, 1, 0.2);
            float alpha = ofMap(i, 0, 5, 50, 255);
            
            ofSetColor(color, alpha);
            ofScale(scale, scale);
            
            drawFlower();
            ofPopMatrix();
        }
        
        ofPopMatrix();
        ofDisableAlphaBlending();
    }
    
    // -------------------------
    void drawFlower()
    {
        ofBeginShape();
        
        for(int i=0; i<nPts; i++)
        {
            float angle = ofMap(i, 0, nPts, 0, M_TWO_PI);
            float x = cos(angle) * 40;
            float y = sin(angle) * 40;
            ofCircle(x,y,10);
        }
        ofEndShape(false);
    }
    
    // -------------------------
    float getAge()
    {
        return ofGetElapsedTimef()-born;
    }
    
    bool dragging;
    
    ofPoint velocity;
    ofPoint position;
    ofColor color;
    
    float innerRadius;
    float outerRadius;
    
    int nPts;
    float rotation;
    float rotationSpeed;
    float born;
};