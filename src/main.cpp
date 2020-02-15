#include <iostream>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

//game objects
sf::RenderWindow window(sf::VideoMode(1280, 720), "Tkyo Spaghetti");

sf::Image icon;

sf::Texture floor_texture;

sf::Sprite floor_sprite;

sf::Music music;
sf::RectangleShape bike_box(sf::Vector2f(100, 45));

sf::RectangleShape floor_box(sf::Vector2f(1280, 50));

sf::Sprite pole_dancer_sprite;
sf::Texture pole_dancer_texture;

sf::Sprite stripper_sprite;
sf::Texture stripper_texture;

sf::Sprite sam_sprite;
sf::Texture sam_texture;

sf::Sprite bike_sprite;
sf::Texture bike_texture;

sf::Event event;

float pole_dancer_accumulator;
float stripper_accumulator;
float sam_accumulator;
float bike_accumulator;
float animate_speed;
float time_of_click;
bool collided;
bool jumping; 
bool game_over;

static void checkCollision()
{ 
    if (bike_box.getGlobalBounds().intersects(floor_box.getGlobalBounds()))
    {
        collided = true;
    }
}

static void update(float elapsed)
{
    float delta = elapsed * 60;

    if (jumping)
    {
        time_of_click += delta;
        if (time_of_click > 15)
        {
            jumping = false;
        }
    }

    if (jumping)
    {
        bike_sprite.move(0, -10);
        bike_box.move(0, -10);
    } 
    else if (!collided)
    {
        bike_sprite.move(0, 4);
        bike_box.move(0, 4);
    }
}

static void poleDancerAnimate(float elapsedTime)
{
    pole_dancer_sprite.setTexture(pole_dancer_texture);
    pole_dancer_sprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
    pole_dancer_accumulator += elapsedTime * animate_speed;

    if (pole_dancer_accumulator > 1 && pole_dancer_accumulator < 2)
    {
        pole_dancer_sprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
    } 
    else if (pole_dancer_accumulator > 2 && pole_dancer_accumulator < 3)
    {
        pole_dancer_sprite.setTextureRect(sf::IntRect(1000, 0, 1000, 1000));
    }
    else if (pole_dancer_accumulator > 3 && pole_dancer_accumulator < 4)
    {
        pole_dancer_sprite.setTextureRect(sf::IntRect(2000, 0, 1000, 1000));
    }
    else if (pole_dancer_accumulator > 4 && pole_dancer_accumulator < 5)
    {
        pole_dancer_sprite.setTextureRect(sf::IntRect(3000, 0, 1000, 1000));
    }
    else if (pole_dancer_accumulator > 5)
    {
        pole_dancer_sprite.setTextureRect(sf::IntRect(4000, 0, 1000, 1000));
        pole_dancer_accumulator = 0;
    }
}

static void stripperAnimate(float elapsedTime)
{
    stripper_sprite.setTexture(stripper_texture);
    stripper_accumulator += elapsedTime * animate_speed;
    stripper_sprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));

    if (stripper_accumulator > 1 && stripper_accumulator < 2)
    {
        stripper_sprite.setTextureRect(sf::IntRect(1000, 0, 1000, 1000));
    } 
    else if (stripper_accumulator > 2 && stripper_accumulator < 3)
    {
        stripper_sprite.setTextureRect(sf::IntRect(2000, 0, 1000, 1000));
    }
    else if (stripper_accumulator > 3 && stripper_accumulator < 4)
    {
        stripper_sprite.setTextureRect(sf::IntRect(3000, 0, 1000, 1000));
    }
    else if (stripper_accumulator > 4 && stripper_accumulator < 5)
    {
        stripper_sprite.setTextureRect(sf::IntRect(4000, 0, 1000, 1000));
    }
    else if (stripper_accumulator > 5)
    {
        stripper_sprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
        stripper_accumulator = 0;
    }
}


static void samAnimate(float elapsedTime)
{

    sam_sprite.setTexture(sam_texture);
    sam_sprite.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
    sam_accumulator += elapsedTime * animate_speed;

    if (sam_accumulator > 1 && sam_accumulator < 2)
    {
        sam_sprite.setTextureRect(sf::IntRect(1000, 0, 1000, 1000));
    } 
    else if (sam_accumulator > 2 && sam_accumulator < 3)
    {
        sam_sprite.setTextureRect(sf::IntRect(2000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 3 && sam_accumulator < 4)
    {
        sam_sprite.setTextureRect(sf::IntRect(3000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 4 && sam_accumulator < 5)
    {
        sam_sprite.setTextureRect(sf::IntRect(4000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 5 && sam_accumulator < 6)
    {
        sam_sprite.setTextureRect(sf::IntRect(5000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 6 && sam_accumulator < 7)
    {
        sam_sprite.setTextureRect(sf::IntRect(6000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 7 && sam_accumulator < 8)
    {
        sam_sprite.setTextureRect(sf::IntRect(7000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 8 && sam_accumulator < 9)
    {
        sam_sprite.setTextureRect(sf::IntRect(8000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 9 && sam_accumulator < 10)
    {
        sam_sprite.setTextureRect(sf::IntRect(9000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 10 && sam_accumulator < 11)
    {
        sam_sprite.setTextureRect(sf::IntRect(10000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 11 && sam_accumulator < 12)
    {
        sam_sprite.setTextureRect(sf::IntRect(11000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 12 && sam_accumulator < 13)
    {
        sam_sprite.setTextureRect(sf::IntRect(12000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 13 && sam_accumulator < 14)
    {
        sam_sprite.setTextureRect(sf::IntRect(13000, 0, 1000, 1000));
    }
    else if (sam_accumulator > 14 && sam_accumulator < 15)
    {
        sam_sprite.setTextureRect(sf::IntRect(14000, 0, 1000, 1000));
        sam_accumulator = 0;
    }

}

static void bikeAnimate(float elapsedTime)
{
    bike_sprite.setTexture(bike_texture);
    bike_sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    bike_accumulator += elapsedTime * animate_speed;

    if (bike_accumulator > 1 && bike_accumulator < 2)
    {
        bike_sprite.setTextureRect(sf::IntRect(200, 0, 200, 200));
    } 
    else if (bike_accumulator > 2 && bike_accumulator < 3)
    {
        bike_sprite.setTextureRect(sf::IntRect(400, 0, 200, 200));
    }
    else if (bike_accumulator > 3 && bike_accumulator < 4)
    {
        bike_sprite.setTextureRect(sf::IntRect(600, 0, 200, 200));
    }
    else if (bike_accumulator > 4 && bike_accumulator < 5)
    {
        bike_sprite.setTextureRect(sf::IntRect(800, 0, 200, 200));
    }
    else if (bike_accumulator > 5 && bike_accumulator < 6)
    {
        bike_sprite.setTextureRect(sf::IntRect(1000, 0, 200, 200));
    }
    else if (bike_accumulator > 6 && bike_accumulator < 7)
    {
        bike_sprite.setTextureRect(sf::IntRect(1200, 0, 200, 200));
    }
    else if (bike_accumulator > 7 && bike_accumulator < 8)
    {
        bike_sprite.setTextureRect(sf::IntRect(1400, 0, 200, 200));
    }
    else if (bike_accumulator > 8 && bike_accumulator < 9)
    {
        bike_sprite.setTextureRect(sf::IntRect(1600, 0, 200, 200));
    }
    else if (bike_accumulator > 9 && bike_accumulator < 10)
    {
        bike_sprite.setTextureRect(sf::IntRect(1800, 0, 200, 200));
    }
    else if (bike_accumulator > 10 && bike_accumulator < 11)
    {
        bike_sprite.setTextureRect(sf::IntRect(2000, 0, 200, 200));
    }
    else if (bike_accumulator > 11 && bike_accumulator < 12)
    {
        bike_sprite.setTextureRect(sf::IntRect(2200, 0, 200, 200));
    }
    else if (bike_accumulator > 12 && bike_accumulator < 13)
    {
        bike_sprite.setTextureRect(sf::IntRect(2400, 0, 200, 200));
    }
    else if (bike_accumulator > 13 && bike_accumulator < 14)
    {
        bike_sprite.setTextureRect(sf::IntRect(2600, 0, 200, 200));
    }
    else if (bike_accumulator > 14 && bike_accumulator < 15)
    {
        bike_sprite.setTextureRect(sf::IntRect(2800, 0, 200, 200));
    }
    else if (bike_accumulator > 15 && bike_accumulator < 16)
    {
        bike_sprite.setTextureRect(sf::IntRect(3000, 0, 200, 200));
    }
    else if (bike_accumulator > 16 && bike_accumulator < 17)
    {
        bike_sprite.setTextureRect(sf::IntRect(3200, 0, 200, 200));
    }
    else if (bike_accumulator > 17 && bike_accumulator < 18)
    {
        bike_sprite.setTextureRect(sf::IntRect(3400, 0, 200, 200));
    }
    else if (bike_accumulator > 18 && bike_accumulator < 19)
    {
        bike_sprite.setTextureRect(sf::IntRect(3600, 0, 200, 200));
    }
    else if (bike_accumulator > 19 && bike_accumulator < 20)
    {
        bike_sprite.setTextureRect(sf::IntRect(3800, 0, 200, 200));
    }
    else if (bike_accumulator > 20 && bike_accumulator < 21)
    {
        bike_sprite.setTextureRect(sf::IntRect(4000, 0, 200, 200));
    }
    else if (bike_accumulator > 21 && bike_accumulator < 22)
    {
        bike_sprite.setTextureRect(sf::IntRect(4200, 0, 200, 200));
    }
    else if (bike_accumulator > 22 && bike_accumulator < 23)
    {
        bike_sprite.setTextureRect(sf::IntRect(4600, 0, 200, 200));
        bike_accumulator = 0;
    }

}

static void render()
{
    
    window.draw(floor_sprite);
    window.draw(bike_box);
    window.draw(floor_box);
    window.draw(bike_sprite);
}

static void input()
{
    
    if (event.type == sf::Event::Closed) 
    {
        
        window.close();
    }
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
    {
        window.close();
    }
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        if (collided)
        {
            if (!jumping)
            {
                time_of_click = 0;
            }

            collided = false;
            jumping = true;
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
    {
       //currently does nothing
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
    {
        //currently does nothing
    }
}

static void loadResources()
{
	icon.loadFromFile("resources/icon.png");

    pole_dancer_texture.loadFromFile("resources/pole_dance_sheet.png");
    
    stripper_texture.loadFromFile("resources/stripper_twerk_sheet.png");

    sam_texture.loadFromFile("resources/sam_sprite_money_sheet.png");

    bike_texture.loadFromFile("resources/bike_sheet.png");
 
	music.openFromFile("resources/cyber_sam.wav");
}

static void init()
{
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);

    bike_sprite.move(110, 450);
    bike_box.move(165, 530);

    floor_sprite.setScale(10, 3);
    floor_sprite.setTexture(floor_texture);
    
    floor_box.move(0, 600);
    floor_sprite.move(0, 600);
    
    animate_speed = 7;

    // music.play();
    // music.setLoop(true);
}


static void gameStart()
{
    // game_over = false;

    // collided = false;

    // jumping = false;
}


int main(int, char const**)
{
    // Create the main window
    loadResources();
    init();

    sf::Clock clock;


    // Start the game loop
    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        
        while (window.pollEvent(event))
        {
            input();
        }
    
        window.clear();
        bikeAnimate(elapsed.asSeconds());
        update(elapsed.asSeconds());
        checkCollision();
        render();
        window.display();
        
    }

    return EXIT_SUCCESS;

}