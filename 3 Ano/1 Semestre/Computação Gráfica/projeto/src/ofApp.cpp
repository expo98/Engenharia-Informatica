#include "ofApp.h"
#include "cg_extras.h"
#include "cg_drawing_extras.h"


//--------------------------------------------------------------
void ofApp::setup() {
    // Set initial positions for paddles and ball
    paddleLeft[0] = ((1920- BORDERWIDTH)/2) + 50;           // X position of left paddle
    paddleLeft[1] = gh() / 2;  // Y position of left paddle
    
    paddleRight[0] = ((1920- BORDERWIDTH)/2) + BORDERWIDTH - 50; // X position of right paddle
    paddleRight[1] = gh() / 2; // Y position of right paddle

    ballPos[0] = gw() / 2;      // Ball X position
    ballPos[1] = gh() / 2;     // Ball Y position

    ballDir[0] = 4.0f;                  // Ball direction (X axis)
    ballDir[1] = 4.0f;                  // Ball direction (Y axis)

    ballSpeed = 8.0f;

    // 2D Border squares sizes (Width, Height)
    borderSizes2D[0] = 10.0f;
    borderSizes2D[1] = 10.0f;

    sideBorderSizes2D[0] = 10.0f;
    sideBorderSizes2D[1] = 240.0f;

    // 3D Border square sizes (Width, Height, Depth)
    borderSizes3D[0] = 10.0f;
    borderSizes3D[1] = 10.0f;
    borderSizes3D[2] = 10.0f;

    sideBorderSizes3D[0] = 10.0f;
    sideBorderSizes3D[1] = 240.0f;
    sideBorderSizes3D[2] = 10.0f;
    

    //Initializes score and timer
    leftScore = 0;
    rightScore = 0;
    timer = 0.0;

    ofSetFrameRate(144);               
    ofBackground(24,25,26);                    // Set background to black
    ofEnableDepthTest();                // Enable depth testing for 3D rendering
}

//--------------------------------------------------------------
void ofApp::update() {

    timer += ofGetLastFrameTime();
    // Update ball position
    updateBall();
    // Check for collisions with paddles
    checkCollisions();
    // Clamp paddles within bounds
    clampPaddles();


    followBall(paddleLeft[1],ballPos[1]); // Makes the left paddle follow the ball

    ofSetWindowTitle("Projeto CG: Pong 2D/2D");
}



//--------------------------------------------------------------p


void ofApp::draw() {
    if (!is3DMode) {

        // Draw in 2D mode
        drawFieldBorder2D();

        ofSetColor(255,0,0);  // Set color to red
       // draw2DRectangle(paddleLeft, paddleWidth, paddleHeight);
        drawRotatedRectangle2D(paddleLeft,paddleWidth,paddleHeight,paddleLeftAngle);
        ofSetColor(0,0,255);  // Set color to blue
        //draw2DRectangle(paddleRight, paddleWidth, paddleHeight);
        drawRotatedRectangle2D(paddleRight,paddleWidth,paddleHeight,paddleRightAngle);

        ofSetColor(255,255,255); // Sets ball color to white
        draw2DRectangle(ballPos, ballRadius * 2, ballRadius * 2);  // Draw ball as 2D rectangle (actually a square)

        drawScoreBoard2D(leftScore,rightScore,timer);

    } else {
        // Draw in 3D mode
        ofEnableDepthTest();
        
        // Convert paddle and ball positions into 3D coordinates
        float paddleLeft3D[3] = {paddleLeft[0], paddleLeft[1], 0};
        float paddleRight3D[3] = {paddleRight[0], paddleRight[1], 0};
        float ball3D[3] = {ballPos[0], ballPos[1], 0};

        drawFieldBorder3D();

        ofSetColor(255,0,0);  // Sets left paddle color to red
        //draw3DBox(paddleLeft3D, paddleWidth, paddleHeight, 10);
        drawRotated3DBox(paddleLeft3D,paddleWidth,paddleHeight,paddleDepth,paddleLeftAngle,RED);
        ofSetColor(0,0,255);  // Sets left paddle color to blue
        //draw3DBox(paddleRight3D, paddleWidth, paddleHeight, 10);
        drawRotated3DBox(paddleRight3D,paddleWidth,paddleHeight,paddleDepth,paddleRightAngle,BLUE);

        ofSetColor(255,255,255); // Sets ball color to white
        draw3DBox(ball3D, ballRadius * 2, ballRadius * 2, ballRadius * 2,WHITE);  // Draw ball as 3D box

        drawScoreBoard2D(leftScore,rightScore,timer);
        ofDisableDepthTest();
        }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    // Handle paddle movement with arrow keys or W/S keys
    if (key == OF_KEY_UP) {
        paddleRight[1] -= paddleSpeed;  // Move right paddle up
    } else if (key == OF_KEY_DOWN) {
        paddleRight[1] += paddleSpeed;  // Move right paddle down
    } 
    
    if (key == OF_KEY_RIGHT){
        paddleRightAngle += rotationSpeed;
    } else if (key == OF_KEY_LEFT){
        paddleRightAngle -= rotationSpeed;
    }

    /*
    if (key == 'w' || key == 'W') {
        paddleLeft[1] -= paddleSpeed;   // Move left paddle up
    } else if (key == 's' || key == 'S') {
        paddleLeft[1] += paddleSpeed;   // Move left paddle down
    }
    
    if (key == 'a' || key == 'A'){
        paddleLeftAngle -= rotationSpeed;
    } else if (key == 'd' || key == 'D') {
        paddleLeftAngle += rotationSpeed;
    }
    */
    //Top View 2D
    if (key == '1') {
        is3DMode = false;  
        isOrthographicView = false;
    }

    // Top view 3D    
    if (key == '2') {
        is3DMode = true; 
        isOrthographicView = false;  
    }

    // Orthographic view 3D
    if (key == '3') {
        is3DMode = true;  // Toggle 3D mode
        isOrthographicView = true; // Toggles Orthographic View
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    // Nothing needs to be done when keys are released in this case
}
