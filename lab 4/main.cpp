#include <iostream>
#include <SFML/Graphics.hpp>
#include <Shapes.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    int n;
    srand(time(0));
    std::cin >> n;
    
    ds::Circle* c = new ds::Circle[n];
    ds::Triagle* t = new ds::Triagle[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int r = rand()%50 + 1;
        c[i].SetUp(x, y, r);
    }
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int r = rand() % 50 + 1;
        t[i].SetUp(x, y, r, 3);
    }
    ds::Rectangle* rect = new ds::Rectangle[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int a = rand() % 50 + 1;
        int b = rand() % 50 + 1;
        rect[i].SetUp(x, y, a, b);
    }
    ds::Rectangle* line = new ds::Rectangle[n];
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int y = rand() % 600;
        int a = rand() % 150 +10;
        line[i].SetUp(x, y, a, 1);
        line[i].ChangeColortoWhite();
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < n; i++)
        {
            window.draw(c[i].Get());
            window.draw(t[i].Get());
            window.draw(rect[i].Get());
            window.draw(line[i].Get());
        }

        window.display();
    }
    
    delete[] c;
    delete[] t;
    delete[] rect;
    delete[] line;
    return 0;
}