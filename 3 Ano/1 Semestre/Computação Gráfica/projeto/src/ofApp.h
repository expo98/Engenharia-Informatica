#pragma once

#include "ofMain.h"
#include "cg_drawing_extras.h" // Include helper functions

#define BORDERWIDTH 1024
#define BORDERHEIGHT 780

#define BORDERTOPPLACE (1080/2 + BORDERHEIGHT/2)
#define BORDERBOTPLACE (1080/2 - BORDERHEIGHT/2)
#define BORDERLEFTPLACE ((1920 - BORDERWIDTH)/2)
#define BORDERRIGHTPLACE ((1920 - BORDERWIDTH)/2 + BORDERWIDTH)

#define RED ofColor(255, 0, 0)    // RGB values for red
#define BLUE ofColor(0, 0, 255)   // RGB values for blue
#define WHITE ofColor(255, 255, 255) // RGB values for white

class ofApp : public ofBaseApp {
public:
    // Core openFrameworks methods
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    // Game state variables
    float paddleLeft[2];    // Position of the left paddle (x, y)
    float paddleRight[2];   // Position of the right paddle (x, y)
    float ballPos[2];       // Position of the ball (x, y)
    float ballDir[2];       // Ball direction vector (x, y)
    float ballSpeed;        // Ball speed

    float paddleSpeed = 20.0f;    // Speed at which paddles move

    // Paddle size variables
    float paddleWidth = 20.0f;  // Paddle width
    float paddleHeight = 100.0f; // Paddle height
    float paddleDepth = 10.0f;
    float ballRadius = 10.0f;    // Radius of the ball

    //Set initial paddle angles and angle speed
    float paddleLeftAngle = 0.0f;  // Rotation angle for the left paddle
    float paddleRightAngle = 0.0f; // Rotation angle for the right paddle
    float rotationSpeed = 6.0f;    // Speed of rotation  

    // Declares field borders variables
    float borderSizes2D[2]; // Width and height of borders squares
    float sideBorderSizes2D[2]; //Width and height of side border rectangles

    float borderSizes3D[3]; // Width and height of borders squares
    float sideBorderSizes3D[3]; //Width and height of side border rectangles

    
    // Score and timer variables
    int leftScore = 0;  // Left player score
    int rightScore = 0; // Right player score
    float timer = 0.0;  // Game timer
    bool is3DMode = false; // Whether the game is in 3D mode
    bool isOrthographicView = false;  // Wheter the view is Orthographic

    

    enum class Side {
        LEFT,
        RIGHT
    };

    // 3D camera
    ofEasyCam cam;

    // Utility methods
    void resetGame();            // Reset ball and paddles to default positions
    void checkCollisions();      // Detect and handle collisions
    void updateBall();           // Move the ball and handle logic
    void ballHitSideWall(Side side);      // Checks if the ball hit the side walls and adds points to the players
    void clampPaddles();         // Prevent paddles from moving out of bounds
    void drawFieldBorder2D();       // Draws the field borders
    void drawFieldBorder3D();       // Draws the 3d field
    void drawScoreBoard2D(int leftScore, int rightScore, int timer);
    void followBall(float paddleYaxis, float ballYaxis); // Makes a paddle Follow the ball
};
