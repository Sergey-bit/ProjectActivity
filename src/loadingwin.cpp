#pragma once
#include <loadingwin.hpp>

#define RECT_WIDTH 2000.0f
#define RECT_HEIGHT 2000.0f

void loadingWin_(Params& p)
{
	p.win.setActive(true);
	p.win.setMouseCursorVisible(false);

	sf::RectangleShape rect;
	sf::Clock clock;
	sf::Shader shader;

	vec2u size = p.win.getSize();

	rect.setSize({ size.x * 1.0f, size.y * 1.0f });
	rect.setFillColor(sf::Color::Transparent);

	size.x = size.x * 2 - 150;
	size.y = 150;

	clock.restart();
	if (!shader.loadFromFile("ProjectActivity\\src\\fragment.glsl", sf::Shader::Fragment))
	{
		std::cout << "Failed to load the shader" << std::endl;
	}

	while (p.win.isOpen() && !p.run)
	{
		sf::Event event;
		while (p.win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				p.win.close();
			}
		}

		p.win.clear();

		shader.setUniform("iResolution", sf::Glsl::Vec2(size.x, size.y));
		shader.setUniform("iTime", clock.getElapsedTime().asSeconds());

		p.background.draw();
		p.win.draw(rect, &shader);

		p.win.display();
	}

	p.win.setActive(false);
	p.win.setMouseCursorVisible(true);
}