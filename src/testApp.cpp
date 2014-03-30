#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    boxW = 1000;
    boxH = 500;
    xSpacing = 64;
    ySpacing = 30;
    //waitTime = 0;
    maxWait = 2000;
    
    col = boxW / xSpacing;		//number of columns
    row = boxH / ySpacing;		//number of rows
    numPetals = col * row;		//total number of petals
    
    numPetalsOn = 0;
    
    
    current = 1.0;
    voltage = 4.5;
    
    offset = 60;
    //changeColor = false;
    
    gui.setup();
    gui.add(waitTime.setup("rate", 0, 0, maxWait));
    gui.add(changeColor.setup("show on", false));
    gui.setPosition(boxW+offset, 30+offset);
    
    
    for(int i = 0; i < numPetals; i++)
    {
        Petal p = *new Petal();
        petals.push_back(p);
    }
    
    for(int i = 0; i < petals.size(); i ++)
    {
        petals[i].setWaitTime((int)ofRandom(200));
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i < petals.size(); i++)
    {
        petals[i].update();
        petals[i].setWaitTime(maxWait-waitTime);
        
        //get a count of how many petals are currently "on"
		if(petals[i].state == true && petals[i].prevState == false)
		{
			numPetalsOn++;
		}
		if(petals[i].state == false && petals[i].prevState == true)
		{
			numPetalsOn--;
		}
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(80);
    gui.draw();
    
    ofPushMatrix();
        ofTranslate(offset, offset);
        
        //draw the petals
        ofNoFill();
        ofSetColor(150, 150, 150);
        ofRect(0,0,boxW-20, boxH);
        //ofNoStroke();
        
        for(int i = 1; i < col; i++)
        {
            for(int j = 1; j < row; j ++)
            {
                ofPushMatrix();
                    ofTranslate(i*xSpacing, j*ySpacing);
                    petals[i*j].display(changeColor);
                ofPopMatrix();
                
            }
        }
        
        //write out the number of petals that are on
        ofFill();
        ofSetColor(255);
        ofDrawBitmapString("number of petals on: " + ofToString(numPetalsOn), boxW , boxH);
        ofDrawBitmapString("current draw @ 4.5v: " + ofToString((int)(numPetalsOn * current)), boxW, boxH + 13);
        ofDrawBitmapString("wattage: " + ofToString((int)(numPetalsOn * current * voltage)), boxW, boxH + 26);
	ofPopMatrix();
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

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
