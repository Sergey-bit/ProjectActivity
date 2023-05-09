#pragma once
#include <loadingwin.hpp>

#define RECT_WIDTH 2000.0f
#define RECT_HEIGHT 2000.0f

void loadingWin_(Params& p, const vec3f& baseColor)
{	
	p.win.setMouseCursorVisible(false);

	sf::RectangleShape rect;
	sf::Clock clock;
	sf::Shader shader;

	vec2u size = p.win.getSize();

	rect.setSize({ size.x * 1.0f, size.y * 1.0f });
	rect.setFillColor(sf::Color::Transparent);

	size.x = size.x * 2 - 300;
	size.y = 300;

	clock.restart();
	if (!shader.loadFromFile("ProjectActivity\\src\\fragment.glsl", sf::Shader::Fragment))
	{
		std::cout << "Failed to load the shader" << std::endl;
	}

	while (p.win.isOpen() && p.run)
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
		shader.setUniform("iTime", 2 * clock.getElapsedTime().asSeconds());
		shader.setUniform("iBaseColor", baseColor);

		p.background.draw();
		p.win.draw(rect, &shader);

		p.win.display();
	}

	p.win.setMouseCursorVisible(true);
}