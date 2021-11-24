#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "lab9");

    //Круг
    sf::CircleShape shape(100.f);
    shape.setOrigin(200, 200);
    shape.setFillColor(sf::Color::Cyan);
    int shape_x = 800, shape_y = 600;
    shape.setPosition(shape_x, shape_y);

    shape_x++;
    shape_y--;
    if (shape_y < 200)
        shape_y = 200;
    shape.setPosition(800, shape_y);


    //Прямоугольник
    sf::RectangleShape shape2(sf::Vector2f(120.f,300.f));
    shape2.setOrigin(60, 300);
    shape2.setFillColor(sf::Color::Green);
    int shape2_x = 500, shape2_y = 600;
    shape2.setPosition(shape2_x, shape2_y);
   
    shape2_x++;
    shape2_y--;
    if (shape2_y < 300)
        shape2_y = 300;
    shape2.setPosition(500, shape2_y);
    

    //Треугольник
    sf::CircleShape shape3(50.f, 3);
    shape3.setOrigin(100, 75);
    shape3.setFillColor(sf::Color::Red);
    int shape3_x = 400, shape3_y = 600;
    shape3.setPosition(shape3_x, shape3_y);

    shape3_x++;
    shape3_y--;
    if (shape3_y < 75)
        shape3_y = 75;
    shape3.setPosition(400, shape3_y);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }


        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);
        window.display();


        std::this_thread::sleep_for(3ms);
    }
   
    return 0;
}
