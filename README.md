# Racer_glut
A simple game using GLUT

The project ‘2D racing game in OpenGL’ is my project for the subject "Cpmputer Graphics".
It is basically a game in an orthogonal top-down view where the player takes control of a car and tries to get the maximum score possible.
The game is completely made using OpenGL in C++ including all graphics and game logic.
Its features can be described as:
•	The game has a start screen, where a car and road scenery is shown along with the name. There is text prompt to press spacebar to start the game, upon pressing which, the game loads the gameplay view.
•	There two keyboard main keys spacebar and esc, spacebar starts the game and esc exits it.
•	There are four game control keys: up, down, left right. Up and down are used to increase the game speed by increasing or decreasing the frame rate. Left and right are used to move the car horizontally.
•	As a player avoids a car, the score increases. Upon colliding with a car, the game ends.
•	There are three different colored cars coming in the opposite direction that the player must avoid by moving.
•	The game plays infinitely until the player crashes with increasing difficulty.

 
 


Computer Graphics Concepts Used:

1.	Polygon Drawing: All the shapes and objects seen in the game are made simply using 2D polygon drawing, there are in-built functions provided in GLUT to draw a polygon for any given set of points.
2.	Polygon Solid Fill: The polygons used are then filled with color using polygon filling algorithms to provide them with a defined solid color internally.
3.	Polygon Gradient Fill: In some areas like user’s car and start screen scenery gradient fill has been applied by slowly shifting fill color from one color to another.
4.	Translation: 2D translation is used on a frame-by-frame basis to move the car horizontally and to move the road and incoming cars vertically. This allows us to actually create a gameplay by allowing for motion on a per frame basis.
5.	Bitmap Text Drawing: Text like instructions and score is drawn on the screen using in-built bitmap text drawing functions which convert input string to set of pixels and place on the screen

![Car Racer](https://user-images.githubusercontent.com/57853436/186638713-d3b0e6f3-6a6d-4d1a-acdb-824b001edeb3.jpg)

![image](https://user-images.githubusercontent.com/57853436/186638897-2879ef5d-9dea-483a-bb51-889b858d7cc9.png)
