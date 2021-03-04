#include <TBG/Player.hpp>
#include <TBG/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "OBJ/bad_guy.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "TBG", sf::Style::Default);

    std::cout << sf::VideoMode::getDesktopMode().height << " " << sf::VideoMode::getDesktopMode().width;
    window.setFramerateLimit(20);
    sf::Texture sprite;

    if (!sprite.loadFromFile("../design/WARRIORTUX.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 0;
    }
    
    sf::Sprite shape;
    shape.setTexture(sprite);

    sf::Texture bT;

    if (!bT.loadFromFile("../design/button.png", sf::IntRect(0, 0, 200, 80)))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 0;
    }

    sf::Sprite button;
    button.setTexture(bT);

    sf::Vector2f button_position(760.f, 460.f);
    button.setPosition(button_position);

    player.set_name("Player");
    player.set_coordinate(pos);

    sf::SoundBuffer sBuffer;

    if (!sBuffer.loadFromFile("../audio/steps.wav"))
    {
        std::cerr << "Error occurred when loading sound buffer from a file!";
        exit(EXIT_FAILURE);
    }

    sf::Sound sound;
    sound.setBuffer(sBuffer);

    sf::Music intro;

    if(!intro.openFromFile("../audio/beeh.wav"))
    {
        std::cerr << "Error caught when loading the musick from a file!";
        return -1;
    }

    intro.play();

    bool status = false;

    window.clear(sf::Color::White);
    window.draw(button);
    window.display();
    
    // run the program as long as the window is open

    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mpos = sf::Mouse::getPosition(window);

            if (mpos.x >= 760 && mpos.x <= 960 && mpos.x >= 480 && mpos.y <= 540)
            {
                std::cout << mpos.x << " " << mpos.y << std::endl;
                intro.stop();
                break;
            }
        }
    }

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            else if (event.type == sf::Event::KeyPressed)
            {
                // if (pos.y + 366 > sf::VideoMode::getDesktopMode().height)
                // {
                //     pos = player.get_coordinate();
                //     pos.y -= 50;
                //     player.set_coordinate(pos);
                //     // continue;
                //     std::cout << "mushaa1" << std::endl;
                //     break;

                // }
                // else if (pos.y  < 0)
                // {
                //     pos = player.get_coordinate();
                //     pos.y += 50;
                //     player.set_coordinate(pos);
                //     // continue;

                //     std::cout << "mushaa2" << std::endl;
                //     break;

                // }
                // else if (pos.x + 366 > sf::VideoMode::getDesktopMode().width)
                // {
                //     pos = player.get_coordinate();
                //     pos.x -= 50;
                //     player.set_coordinate(pos);
                //     // continue;

                //     std::cout << "mushaa3" << std::endl;
                //     break;


                // }
                // else if (pos.x  < 0)
                // {
                //     pos = player.get_coordinate();

                //     pos.x += 50;
                //     player.set_coordinate(pos);
                //     // continue;

                //     std::cout << "mushaa4" << std::endl;
                //     break;

                // }
                
                if (event.key.code == sf::Keyboard::Left)
                {
                    pos = player.get_coordinate();
                    pos.x -= 50;
                    player.set_coordinate(pos);
                    sound.play();
                }

                else if (event.key.code == sf::Keyboard::Right)
                {
                    pos = player.get_coordinate();
                    pos.x += 50;
                    player.set_coordinate(pos);
                    sound.play();
                }

                else if (event.key.code == sf::Keyboard::Down)
                {
                    pos = player.get_coordinate();
                    pos.y += 50;
                    player.set_coordinate(pos);
                    sound.play();
                }

                else if (event.key.code == sf::Keyboard::Up)
                {
                    pos = player.get_coordinate();
                    pos.y -= 50;
                    player.set_coordinate(pos);
                    sound.play();
                }     
            }
        }

        window.clear(sf::Color::White);

        std::cout << pos.x << " " << pos.y << std::endl;
        
        pos = player.get_coordinate();

        shape.setPosition(pos.x, pos.y);

        window.draw(shape);

        window.display();
    }

    return 0;
}