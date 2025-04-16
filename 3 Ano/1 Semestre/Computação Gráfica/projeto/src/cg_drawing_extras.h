/* CG_EXTRAS
Collection of functions to help speed up programming in OF

Developed for the Computer Graphics course @:
Informatics Engineering Department
University of Coimbra
by
André Perrotta & Evgheni Polisciuc

Coimbra, 09/2023
*/

#ifndef CG_DRAWING_EXTRAS_H
#define CG_DRAWING_EXTRAS_H

#include "ofMain.h"

// Short function to get screen width
inline float gw() {
    return ofGetWidth();
}

// Short function to get screen height
inline float gh() {
    return ofGetHeight();
}


// Draw a 2D rectangle using float pairs and glVertex2d
inline void draw2DRectangle(float position[2], float width, float height) {
    float x = position[0];
    float y = position[1];
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    glBegin(GL_QUADS);
    glVertex2d(x - halfWidth, y - halfHeight); // Top-left
    glVertex2d(x + halfWidth, y - halfHeight); // Top-right
    glVertex2d(x + halfWidth, y + halfHeight); // Bottom-right
    glVertex2d(x - halfWidth, y + halfHeight); // Bottom-left
    glEnd();
}

// Draw a 3D box using float triplets and glVertex3d
inline void draw3DBox(float position[3], float width, float height, float depth, ofColor faceColor) {
    float x = position[0];
    float y = position[1];
    float z = position[2];

    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = depth / 2.0f;

    ofSetColor(faceColor);
    glBegin(GL_QUADS);

    // Front face
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth);
    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth);

    // Back face
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth);
    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth);
    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth);

    // Left face
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth);
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth);
    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth);

    // Right face
    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth);
    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth);

    // Top face
    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth);
    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth);

    // Bottom face
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth);
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth);
    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth);

    glEnd();
}

inline void drawBoxOutlines(float position[3], float width, float height, float depth) {
    float x = position[0];
    float y = position[1];
    float z = position[2];  

    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = depth / 2.0f;

    ofSetColor(0);
    glLineWidth(3);
    glBegin(GL_LINES);

    // Front face edges
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth); // Bottom-left
    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth); // Bottom-right

    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth); // Bottom-right
    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth); // Top-right

    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth); // Top-right
    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth); // Top-left

    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth); // Top-left
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth); // Bottom-left

    // Back face edges
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth); // Bottom-left
    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth); // Bottom-right

    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth); // Bottom-right
    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth); // Top-right

    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth); // Top-right
    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth); // Top-left

    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth); // Top-left
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth); // Bottom-left

    // Vertical edges between front and back faces
    glVertex3d(x - halfWidth, y - halfHeight, z + halfDepth); // Front-left-bottom
    glVertex3d(x - halfWidth, y - halfHeight, z - halfDepth); // Back-left-bottom

    glVertex3d(x + halfWidth, y - halfHeight, z + halfDepth); // Front-right-bottom
    glVertex3d(x + halfWidth, y - halfHeight, z - halfDepth); // Back-right-bottom

    glVertex3d(x + halfWidth, y + halfHeight, z + halfDepth); // Front-right-top
    glVertex3d(x + halfWidth, y + halfHeight, z - halfDepth); // Back-right-top

    glVertex3d(x - halfWidth, y + halfHeight, z + halfDepth); // Front-left-top
    glVertex3d(x - halfWidth, y + halfHeight, z - halfDepth); // Back-left-top

    glEnd();
}

inline void drawRotatedRectangle2D(float position[2], float width, float height, float angle) {
    
    ofPushMatrix(); // Save the current coordinate system
    
    // Translate to the center of the paddle
    ofTranslate(position[0], position[1]);
    
    // Rotate the coordinate system
    ofRotateDeg(angle); // Rotate by the given angle in degrees

    // Draw the rectangle centered at the origin
    glBegin(GL_QUADS);
    glVertex2d(-width / 2, -height / 2); // Top-left corner
    glVertex2d(width / 2, -height / 2);  // Top-right corner
    glVertex2d(width / 2, height / 2);   // Bottom-right corner
    glVertex2d(-width / 2, height / 2);  // Bottom-left corner
    glEnd();

    ofPopMatrix(); // Restore the previous coordinate system
}

inline void drawRotated3DBox(float position[3], float width, float height, float depth, float angle, ofColor faceColor){
    
    float rotationPos[3] = {0,0,0};

    ofPushMatrix(); // Save the current coordinate system

    //Translate to the center of the paddle
    ofTranslate(position[0],position[1],position[2]);

    //Rotate the coordinate system
    ofRotate(angle,0,0,1);

    //Draws the 3d boxes (centered at the origin aget translation)

    draw3DBox(rotationPos,width,height,depth,faceColor);
    drawBoxOutlines(rotationPos,width,height,depth);

    ofPopMatrix();

}
#endif
