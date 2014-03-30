#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Petal.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int boxW ;		//width of bounding box
    int boxH ;			//height of bounding box
    int xSpacing;		//horizontal spacing
    int ySpacing;		//vertical spacing
    //int waitTime;			//time/rate variable
    int maxWait; 		//set a max for time/rate variable
    
    int col;		//number of columns
    int row;		//number of rows
    int numPetals;		//total number of petals
    int numPetalsOn;			//keep track of how many petals are being powered
    
    float current;   		//current (amps) of each petal
    float voltage;			//voltage for nitinol
    
    int offset = 60;
    //bool changeColor = false;
    
    vector<Petal> petals;

    
    ofxPanel gui;
    ofxIntSlider waitTime;
    ofxToggle changeColor;
    
    
    
    
    
    
		
};
