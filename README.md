<h1 align="center">Jetpack Joyride in OpenGL</h1>

#### Author - Himanshu Maheshwari

The given game is a simulation of famous jetpack joyride game. The game has been wiritten in c++ and openGL. Open Graphics Library(OpenGL) is a cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics.

#### How to run?
(Showing it for Linux, similar commands could be used for other platforms)
* First install OpenGL.
        
        1) For Fedora use - `sudo pkgconf-pkg-config dnf install glew-devel glfw-devel glm-devel cmake pkgconf`
        2) For Ubuntu use - `sudo apt install libglew-dev libglfw3-dev libglm-dev cmake pkg-config`
* Then git clone the given repo.
* Make directory `build` and cd into it.
* After that run `cmake ..`
* After that run `make`
* All the pre processing is done. Now to run the game use command `./graphics_asgn1`


#### Gameplay
| KEY | ACTION|
|-----|-------|
| A|Move left|
|D|Move right|
|W|Move up|
|B|Release Water Ballon|
|Q or Esc key|Quit the game|
| Space key| Propulsion|
|Scroll Up|Zoom in|
|Scroll Down|Zoom out|
|S| original zoom|

#### Features
* There are four enemies:
1)Fire line
2)Fire Beam
3)Boomerang
4)Dragon
* Number of lives remaining will be shown on top left corner and score on top right corner.
* Diamonds will increase life by one and super coin will increase the score by 20.
* Once you enter semi-circular tunnel then no enemy can kill you and you follow its path.
* Magnet will attract the player towards it and will have its own magnetic field.
* For detailed description of features please refer to Description.pdf. All the features mentioned in it are implemented.

#### Screenshots
<img src="Screen Shots/1.png" alt="1"></img>
<img src="Screen Shots/2.png" alt="2"></img>
<img src="Screen Shots/3.png" alt="3"></img>
<img src="Screen Shots/4.png" alt="4"></img>
<img src="Screen Shots/5.png" alt="5"></img>

#### Cheers!!!
