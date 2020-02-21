#include <iostream>
#include <IPlatform.hpp>

Platform::Platform(sf::Texture _texture, int length, int x, int y)
{
    this->texture = _texture;
    this->x = 0;
    this->y = 0;
    this->createPlatform(length, x, y);
};

void Platform::move(int x, int y)
{

    for(int i = 0; i < this->sprites.size(); i++)
    {
        this->sprites[i].move(x, y);
    }

    for(int i = 0; i < this->bounds.size(); i++)
    {
        this->bounds[i].move(x, y);
    }
};

void Platform::render(sf::RenderWindow &window)
{

    for (int i = 0; i < this->sprites.size(); i++)
    {
        window.draw(sprites[i]);
    }
  
};

void Platform::renderCollider(sf::RenderWindow &window)
{
    for (int i = 0; i < this->bounds.size(); i++)
    {
        window.draw(bounds[i]);
    }
}

void Platform::createPlatform(int _midSectionlength, int x, int y)
{
    
    sf::Sprite street_sprite_beginning;
    sf::Sprite street_sprite_end;

    street_sprite_beginning.setTexture(this->texture);
    street_sprite_beginning.setTextureRect(sf::IntRect(0, 0, 200, 200));
    street_sprite_beginning.setScale(3, 3);
    street_sprite_beginning.move(x, y); 
    sprites.push_back(street_sprite_beginning);


    sf::RectangleShape frontBound = sf::RectangleShape(sf::Vector2f(300, 20));
    frontBound.setFillColor(sf::Color::Transparent);
    frontBound.setOutlineThickness(1);
    frontBound.setOutlineColor(sf::Color(255, 255, 255));
    frontBound.move((x + 170), (y + 125));
    bounds.push_back(frontBound);


    
    for (int i = 0; i < _midSectionlength; i++ )
    {
        x = x + 300; //Platform segments should be placed further along the y segment
        sf::Sprite middleSection;
        middleSection.setTexture(this->texture);
        middleSection.setTextureRect(sf::IntRect(200, 0, 200, 200));
        middleSection.setScale(3, 3);
        middleSection.move(x, y);
        this->sprites.push_back(middleSection);

        sf::RectangleShape midBounds = sf::RectangleShape(sf::Vector2f(300, 20));
        midBounds.setFillColor(sf::Color::Transparent);
        midBounds.setOutlineThickness(1);
        midBounds.setOutlineColor(sf::Color(255, 255, 255));
        midBounds.move((x + 170), (y + 125));
        bounds.push_back(midBounds);

    }
    
    x = x + 300;
    street_sprite_end.setTexture(this->texture);
    street_sprite_end.setTextureRect(sf::IntRect(400, 0, 200, 200));
    street_sprite_end.setScale(3, 3);
    street_sprite_end.move(x, y);
    this->sprites.push_back(street_sprite_end);

    sf::RectangleShape endBounds = sf::RectangleShape(sf::Vector2f(300, 20));
    endBounds.setFillColor(sf::Color::Transparent);
    endBounds.setOutlineThickness(1);
    endBounds.setOutlineColor(sf::Color(255, 255, 255));
    endBounds.move((x + 170), (y + 125));
    bounds.push_back(endBounds);


}

std::vector<sf::RectangleShape> Platform::getBounds()
{
    return bounds;
};

