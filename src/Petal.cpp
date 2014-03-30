//
//  Petal.cpp
//  solar_petals_oF
//
//  Created by Jakob Marsico on 3/27/14.
//
//

#include "Petal.h"

Petal::Petal(){


    locX = 0;
    locY = 0;
    h = 20;
    w = 60;
    counter = 0;
    closeCounts = 70;
    openCounts = 90;
    //waitCoeff = _waitTime;
    waitCounts = 0;
    state = false;

}

//-----------------------------------------------------------
void Petal::setWaitTime(int _waiter){
    waitVar = _waiter;
    //waitCounts = waitCoeff + waitVar;
}


//----------------------------------------------------------
void Petal::update()
{
    
    //prepare for any state changes
    prevState = state;
    
    //close the petal
    if(counter > 0 && counter < closeCounts)
    {
        state = true;
        w = w - 0.5;
    }
    
    //open the petal
    if(counter > closeCounts && counter < closeCounts + openCounts)
    {
        state = false;
        w = w + 0.5;
    }
    
    //wait and then reset
    if(counter >= (closeCounts + openCounts + waitCounts))
    {
        state = false;
        counter = 0;
        waitCounts = (int)ofRandom(0,waitVar);
    }
    
    //increment counter
    counter++;
    
    //constrain width
    w = ofClamp(w, 20, 60);
    
    
    //logging for turnOn and turn Off
    if(prevState == false && state == true)
    {
        //ofLog() << "turnedOn";
    }
    if(prevState == true && state == false)
    {
        //ofLog() << "turnedOFF";
    }
    
}


//----------------------------------------------------------
void Petal::display(bool changeColor)
{
    
    if(state && changeColor)
    {
        //ofColor c = #ba8d70;
        ofSetHexColor(0xba8d70);
        
    }else{
        ofFill();
        ofSetColor(200);
    }
    ofEllipse(locX, locY, w, h);
    
}
