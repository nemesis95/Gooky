#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>


int windowWidth = 1000;
int windowHeight = 600;
int halfWinWidth = windowWidth/2;
int halfWinHeight = windowHeight/2;

using namespace std;
using namespace sf;

class platformClass{
public:
                                                            float xpos=0;
                                                            float ypos=0;
                                                            float xvel = 0;
                                                            float yvel = 0;
    platformClass(float xpos, float ypos){
        xpos=xpos;
        ypos=ypos;

    }


};

class playerClass{

public:
    bool playerFaceRight;

    bool onGround=false;

    float xpos=0;
    float ypos=0;
    float xvel = 0;
    float yvel = 0;
    playerClass(){
        playerFaceRight = true;


    }
    void updateGround(bool onGround)
    {
     if(ypos>450){
        onGround=true;
        yvel=0;
       }
    }
    void update(bool playerUp,bool playerDown,bool playerRight,bool playerLeft){
        if(playerRight){
            playerFaceRight=true;
            xvel=0.45;

        }
        if(playerLeft){
            playerFaceRight=false;
            xvel=-0.45;
        }
        if(playerUp){
            yvel=-0.45;
            yvel;
        }
        if(playerDown){
            yvel=0.45;
        }
        if(!(playerRight || playerLeft)){
            xvel=0;

        }
        if(onGround == true){
            yvel=0;

        }
        xpos += xvel;
        ypos += yvel;
        if(!(playerUp || playerDown)){
            yvel=0.75;
        }

                                      ///SRediti gravitaciju i endline****
        ///collide();
    cout<<xpos<<endl;
    cout<<ypos<<endl;
    cout<<onGround<<endl;
    }


};

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(windowWidth,windowHeight), "Gooky");

    bool playerUp, playerLeft, playerRight, playerDown = false;
    bool onGround;


    playerClass playerObject;


    Texture ghostTextureR;
    ghostTextureR.loadFromFile("data/images/right.png");
    Sprite ghostSpriteR(ghostTextureR);

    Texture platformTexture1;
    platformTexture1.loadFromFile("data/images/platform2.png");
    Sprite platformSprite1(platformTexture1);//
    Texture platformTexture2;
    platformTexture2.loadFromFile("data/images/platform2.png");
    Sprite platformSprite2(platformTexture2);////
    Texture platformTexture3;
    platformTexture3.loadFromFile("data/images/platform.png");
    Sprite platformSprite3(platformTexture3);
    Texture doorTexture;
    doorTexture.loadFromFile("data/images/door.png");
    Sprite doorSprite(doorTexture);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
        if(Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
        if(Keyboard::isKeyPressed(Keyboard::Up)) playerUp = true;
        if(Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Up))) playerUp=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft=false;
        if(!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight=false;



        playerObject.update(playerUp,playerDown,playerRight,playerLeft);
        //if(Keyboard::isKeyPressed(Keyboard::Up)) onGround=false;
        if(Keyboard::isKeyPressed(Keyboard::Up)) onGround=false;
        playerObject.updateGround(onGround);

        // Clear screen
        app.clear();
        platformSprite3.setPosition(510, 500);
        app.draw(doorSprite);
        doorSprite.setPosition(510, 185);

        app.draw(ghostSpriteR);
        ghostSpriteR.move(Vector2f(playerObject.xvel,playerObject.yvel));

        app.draw(platformSprite1);
        platformSprite1.setPosition(0, 500);
        app.draw(platformSprite2);
        platformSprite2.setPosition(255, 500);
        app.draw(platformSprite3);

        ///ghostSpriteR.move(Vector2f(playerObject.xvel,playerObject.yvel));

        // Draw the sprite

        // Update the window
        app.display();

    }

    return EXIT_SUCCESS;
}
