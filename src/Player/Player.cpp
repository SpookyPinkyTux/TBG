#include <TBG/Player.hpp>
#include <TBG/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "TBG", sf::Style::Default);


    sf::Texture sprite;


    if (!sprite.loadFromFile("../design/WARRIORTUX.png"))
    {
        std::cout << "Could not load texture" << std::endl;
        return 0;
    }
    

    sf::Sprite shape;
    shape.setTexture(sprite);


    player::Position pos{0, 0};


    player::Player player;


    player.set_name("Player");
    player.set_coordinate(pos);


    sf::SoundBuffer sBuffer;


    if (!sBuffer.loadFromFile("../audio/steps.wav"))
    {
        std::cerr << "Error occurred when loading sound buffer from a file!";
        exit(EXIT_FAILURE);
    }

    // button creation
    sf::RectangleShape button(sf::Vector2f(100, 150));

    button.setPosition(0, 0);
    
    //button color
    button.setFillColor(sf::Color(150, 50, 250));

    //button border
    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color(250, 150, 100));

    sf::Sound sound;
    sound.setBuffer(sBuffer);

    // run the program as long as the window is open
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
                if (event.key.code == sf::Keyboard::Left)
                {
                    pos = player.get_coordinate();
                    pos.x -= 50;
                    player.set_coordinate(pos);
                    sound.play();
                }

                else if(event.key.code == sf::Keyboard::Right)
                {
                    pos = player.get_coordinate();
                    pos.x += 50;
                    player.set_coordinate(pos);
                    sound.play();
                }

                else if(event.key.code == sf::Keyboard::Down)
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
        
         // button press function 
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << button.getPosition().x << " " << button.getPosition().y;
                sf::Vector2i mousePosition = sf::Mouse::getPosition();

                // if (mousePosition.x >= 0 && mousePosition.x <= 100 && mousePosition.y >= 0 && mousePosition.y <= 150)
                // {
                //     button.setPosition(100,50);
                // }
                
            }
            
        }

        window.clear(sf::Color::White);

        shape.setPosition(pos.x, pos.y);
        window.draw(shape);
        window.draw(button);

        window.display();
    }

    return 0;
}