#include <Animator.hpp>


Animator::Animator(int _frameCount,
                   float _speed,
                   float _width,
                   float _height)
{
    frameCount = _frameCount - 1; //indexing starts at zero
    speed = _speed;
    width = _width;
    height = _height;
};

SDL_Texture* Animator::Animate(float elapsedTime, SDL_Texture* _sprite)
{
    animationFrameTimer += elapsedTime * speed;
    
    int frame = floor(animationFrameTimer);

    int framePosition = frame * width;
    
    if (frame >= frameCount)
    {
        animationFrameTimer = 0;
        frame = 0;
    } 
   // _sprite.setTextureRect(sf::IntRect(framePosition, 0, width, height));
    
    return _sprite;
};