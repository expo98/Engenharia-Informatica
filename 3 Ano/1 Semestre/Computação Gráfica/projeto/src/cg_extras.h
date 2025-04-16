#ifndef CG_EXTRAS_H
#define CG_EXTAS_H

#include "ofApp.h"
#include "ofMain.h"
#include "cg_drawing_extras.h"


//--------------------------------------------------------------
void ofApp::updateBall() {
    // Update ball position based on direction
    ballPos[0] += ballDir[0];
    ballPos[1] += ballDir[1];

    // Bounce off top and bottom screen boundaries
    if (ballPos[1] - ballRadius <= BORDERBOTPLACE) {
        ballPos[1] = BORDERBOTPLACE + ballRadius;
        ballDir[1] *= -1;  // Reverse the Y direction
    }
    else if (ballPos[1] + ballRadius >= BORDERTOPPLACE){
        ballPos[1] = BORDERTOPPLACE - ballRadius;
        ballDir[1] *=-1;
    }

     // Check if the ball is within the vertical range of the hole
    bool ballInsideHole = (ballPos[1] < BORDERTOPPLACE - 250 && ballPos[1] > BORDERBOTPLACE + 250);

    // Scoring conditions: Ball is inside the hole and passes the side walls
    if (ballPos[0] - ballRadius <= BORDERLEFTPLACE && ballInsideHole) {
        ballHitSideWall(Side::LEFT); 
    }
    else if (ballPos[0] + ballRadius >= BORDERRIGHTPLACE && ballInsideHole) {
        ballHitSideWall(Side::RIGHT); 
    }
    
    // Ball bounces off left wall when outside the hole
    else if (ballPos[0] - ballRadius <= BORDERLEFTPLACE && !ballInsideHole) {
        ballPos[0] = BORDERLEFTPLACE + ballRadius;  
        ballDir[0] *= -1;  
    }
    // Ball bounces off right wall when outside the hole
    else if (ballPos[0] + ballRadius >= BORDERRIGHTPLACE && !ballInsideHole) {
        ballPos[0] = BORDERRIGHTPLACE - ballRadius;  
        ballDir[0] *= -1;  
    }

}

void ofApp::ballHitSideWall(Side side) {

    if( side == Side::RIGHT){
        //Adicionar código para dar pontos ao jogador do lado direito
        // Adicionar confetis da cor do jogador da esquerda
        leftScore++;

    } else if ( side == Side::LEFT){
        // Adicionar código para dar ponto ao jogador do lado esquerdo
        // Adicionar confetis da cor do jogador da direita
        rightScore++;

    }

    resetGame();
}

//--------------------------------------------------------------
void ofApp::checkCollisions() {
    // Left Paddle Collision
    if (ballPos[0] - ballRadius <= paddleLeft[0] + paddleWidth / 2 &&
        ballPos[1] >= paddleLeft[1] - paddleHeight / 2 &&
        ballPos[1] <= paddleLeft[1] + paddleHeight / 2) {
        
        // Calculate paddle surface normal
        float normalX = cos(ofDegToRad(paddleLeftAngle));
        float normalY = sin(ofDegToRad(paddleLeftAngle));

        // Reflect the ball
        float dotProduct = ballDir[0] * normalX + ballDir[1] * normalY;
        ballDir[0] = ballDir[0] - 2 * dotProduct * normalX;
        ballDir[1] = ballDir[1] - 2 * dotProduct * normalY;

        // Adjust ball position to prevent sticking
        ballPos[0] = paddleLeft[0] + paddleWidth / 2 + ballRadius;
    }

    // Right Paddle Collision
    if (ballPos[0] + ballRadius >= paddleRight[0] - paddleWidth / 2 &&
        ballPos[1] >= paddleRight[1] - paddleHeight / 2 &&
        ballPos[1] <= paddleRight[1] + paddleHeight / 2) {
        
        // Calculate paddle surface normal
        float normalX = cos(ofDegToRad(paddleRightAngle));
        float normalY = sin(ofDegToRad(paddleRightAngle));

        // Reflect the ball
        float dotProduct = ballDir[0] * normalX + ballDir[1] * normalY;
        ballDir[0] = ballDir[0] - 2 * dotProduct * normalX;
        ballDir[1] = ballDir[1] - 2 * dotProduct * normalY;

        // Adjust ball position to prevent sticking
        ballPos[0] = paddleRight[0] - paddleWidth / 2 - ballRadius;
    }

    float speed = sqrt(ballDir[0] * ballDir[0] + ballDir[1] * ballDir[1]);
    ballDir[0] /= speed;
    ballDir[1] /= speed;

    ballDir[0] *= ballSpeed;
    ballDir[1] *= ballSpeed;

}

//--------------------------------------------------------------
void ofApp::clampPaddles() {

    // Clamp left paddle position within screen bounds
    paddleLeft[1] = ofClamp(paddleLeft[1], BORDERBOTPLACE + paddleHeight / 2 + borderSizes2D[0], BORDERTOPPLACE - paddleHeight / 2 - borderSizes2D[0]);

    // Clamp right paddle position within screen bounds
    paddleRight[1] = ofClamp(paddleRight[1], BORDERBOTPLACE + paddleHeight / 2 + borderSizes2D[0], BORDERTOPPLACE - paddleHeight / 2 - borderSizes2D[0]);

    //Clamp right paddle angle within 60º 
    paddleRightAngle = ofClamp(paddleRightAngle, -30, 30);

    //Clamp left paddle angle within 60º
    paddleLeftAngle = ofClamp(paddleLeftAngle,-30,30);


    paddleLeftAngle *= 0.99;  // Gradually reduce angle
    paddleRightAngle *= 0.99; // toward neutral (0 degrees)


}

//--------------------------------------------------------------
void ofApp::resetGame() {
    // Reset ball to the center and randomize its direction
    ballPos[0] = gw() / 2;
    ballPos[1] = gh() / 2;
    
    // Randomize the X direction
    ballDir[0] = ofRandom(-4, 4);  // Randomize X direction

    // Ensures the ball's spawn value isn't too low as to spawn it with a good amount of speed
    do{
        ballDir[0] = ofRandom(-4, 4);
    } while (abs(ballDir[0]) < 2);
    
    // If ballDir[0] is too small, we make it a valid random number to avoid zero horizontal movement
    if (ballDir[0] == 0) {
        ballDir[0] = ofRandom(-4, 4);
    }

    // Calculate the Y direction based on the X direction to ensure the angle is within ±45°
    ballDir[1] = ofRandom(-1, 1) * abs(ballDir[0]);  // Restrict Y direction based on X (±45 degrees)

    // Ensure the ball always has both horizontal and vertical movement
    if (ballDir[0] == 0) {
        ballDir[0] = ofRandom(-4, 4);
    }
}


void ofApp::drawFieldBorder2D()   {


    float borderPlacement[2];

    borderPlacement[1] = BORDERTOPPLACE;
    // Draws the upper border 
    for(int i = BORDERLEFTPLACE; i< BORDERRIGHTPLACE; i+= borderSizes2D[0]*2)
    {
        borderPlacement[0] = i;
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255)); // Sets the border color as random (it's funnier)
        draw2DRectangle(borderPlacement,borderSizes2D[0],borderSizes2D[1]);
    }

    // Draws the lower border

    borderPlacement[1] = BORDERBOTPLACE;
    for(int i = BORDERLEFTPLACE; i<BORDERRIGHTPLACE; i+= borderSizes2D[0]*2)
    {
        borderPlacement[0] = i;
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255)); // Sets the border color as random (it's funnier)
        draw2DRectangle(borderPlacement,borderSizes2D[0],borderSizes2D[1]);
    }


    // Draws left side border
    borderPlacement[0] = BORDERLEFTPLACE;
    borderPlacement[1] = BORDERBOTPLACE + borderSizes2D[0] + sideBorderSizes2D[1]/2;
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255)); // Sets the border color as random (it's funnier)
    
    draw2DRectangle(borderPlacement, sideBorderSizes2D[0], sideBorderSizes2D[1]);
    borderPlacement[1] = BORDERTOPPLACE + - borderSizes2D[0] -sideBorderSizes2D[1]/2;
    draw2DRectangle(borderPlacement, sideBorderSizes2D[0], sideBorderSizes2D[1]);

    borderPlacement[0] = BORDERRIGHTPLACE;
    borderPlacement[1] = BORDERBOTPLACE + borderSizes2D[0] + sideBorderSizes2D[1]/2;
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255)); // Sets the border color as random (it's funnier)
    
    draw2DRectangle(borderPlacement, sideBorderSizes2D[0], sideBorderSizes2D[1]);
    borderPlacement[1] = BORDERTOPPLACE + - borderSizes2D[0] -sideBorderSizes2D[1]/2;
    draw2DRectangle(borderPlacement, sideBorderSizes2D[0], sideBorderSizes2D[1]);


}

void ofApp::drawFieldBorder3D() {

    float borderPlacement[3];

    borderPlacement[2] =0; //It's on the ground

    // Draw the upper border
    borderPlacement[1] = BORDERTOPPLACE;
    for (int i = BORDERLEFTPLACE; i < BORDERRIGHTPLACE; i += borderSizes3D[0] * 2) {
        borderPlacement[0] = i;
        ofColor randomColor(ofRandom(255), ofRandom(255), ofRandom(255));  // Generate a random color for each border cube
        ofSetColor(randomColor);  // Set the color for the current border
        draw3DBox(borderPlacement, borderSizes3D[0], borderSizes3D[1], borderSizes3D[2], randomColor);
        drawBoxOutlines(borderPlacement,borderSizes3D[0],borderSizes3D[1],borderSizes3D[2]);
    }

    // Draw the lower border
    borderPlacement[1] = BORDERBOTPLACE;
    for (int i = BORDERLEFTPLACE; i < BORDERRIGHTPLACE; i += borderSizes2D[0] * 2) {
        borderPlacement[0] = i;
        ofColor randomColor(ofRandom(255), ofRandom(255), ofRandom(255));  // Generate a random color for each border
        ofSetColor(randomColor);  // Set the color for the current border
        draw3DBox(borderPlacement, borderSizes3D[0], borderSizes3D[1], borderSizes3D[2], randomColor);
        drawBoxOutlines(borderPlacement,borderSizes3D[0],borderSizes3D[1],borderSizes3D[2]);

    }

    // Draw left side border
    borderPlacement[0] = BORDERLEFTPLACE;
    borderPlacement[1] = BORDERBOTPLACE + borderSizes2D[0] + sideBorderSizes3D[1] / 2;
    ofColor leftRandomColor(ofRandom(255), ofRandom(255), ofRandom(255));  // Random color for the upper left side
    ofSetColor(leftRandomColor);
    draw3DBox(borderPlacement, sideBorderSizes3D[0], sideBorderSizes3D[1], sideBorderSizes3D[2], leftRandomColor);
    drawBoxOutlines(borderPlacement,sideBorderSizes3D[0],sideBorderSizes3D[1],sideBorderSizes3D[2]);


    borderPlacement[1] = BORDERTOPPLACE + -borderSizes2D[0] - sideBorderSizes2D[1] / 2;
    ofColor leftRandomColor2(ofRandom(255), ofRandom(255), ofRandom(255));  // Random color for the bottom left side box
    ofSetColor(leftRandomColor2);
    draw3DBox(borderPlacement, sideBorderSizes3D[0], sideBorderSizes3D[1], sideBorderSizes3D[2], leftRandomColor2);
    drawBoxOutlines(borderPlacement,sideBorderSizes3D[0],sideBorderSizes3D[1],sideBorderSizes3D[2]);

    // Draw right side border
    borderPlacement[0] = BORDERRIGHTPLACE;
    borderPlacement[1] = BORDERBOTPLACE + borderSizes2D[0] + sideBorderSizes2D[1] / 2;
    ofColor rightRandomColor(ofRandom(255), ofRandom(255), ofRandom(255));  // Random color for the upper right side
    ofSetColor(rightRandomColor);
    draw3DBox(borderPlacement, sideBorderSizes3D[0], sideBorderSizes3D[1], sideBorderSizes3D[2], rightRandomColor);
    drawBoxOutlines(borderPlacement,sideBorderSizes3D[0],sideBorderSizes3D[1],sideBorderSizes3D[2]);

    borderPlacement[1] = BORDERTOPPLACE + -borderSizes2D[0] - sideBorderSizes2D[1] / 2;
    ofColor rightRandomColor2(ofRandom(255), ofRandom(255), ofRandom(255));  // Random color for the bottom right side box
    ofSetColor(rightRandomColor2);
    draw3DBox(borderPlacement, sideBorderSizes3D[0], sideBorderSizes3D[1], sideBorderSizes3D[2], rightRandomColor2);
    drawBoxOutlines(borderPlacement,sideBorderSizes3D[0],sideBorderSizes3D[1],sideBorderSizes3D[2]);

}

void ofApp::drawScoreBoard2D(int leftScore, int rightScore, int timer){
    // Draw score
        ofSetColor(255); // White color for score
        ofDrawBitmapString("Left Score: " + ofToString(leftScore), BORDERLEFTPLACE + 100 ,BORDERBOTPLACE + 50);
        ofDrawBitmapString("Right Score: " + ofToString(rightScore), BORDERRIGHTPLACE - 150 , BORDERBOTPLACE + 50);
        
        // Draw timer
        ofDrawBitmapString("Time: " + ofToString(timer, 2), BORDERLEFTPLACE + BORDERWIDTH/2, BORDERBOTPLACE + 50);
}


void ofApp::followBall(float paddleYaxis, float ballYaxis){
    // Make the left paddle follow the ball in Y-axis
    const float trackingSpeed = 2.0f; // Adjust speed for smoother movement
    if (paddleLeft[1] < ballPos[1]) {
        paddleLeft[1] += trackingSpeed; // Move paddle down to follow the ball
    } else if (paddleLeft[1] > ballPos[1]) {
        paddleLeft[1] -= trackingSpeed; // Move paddle up to follow the ball
    }
}
#endif