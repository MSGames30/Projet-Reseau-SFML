#include "PollEventManager.h"



PollEventManager::PollEventManager()
{
}


PollEventManager::~PollEventManager()
{
}

void PollEventManager::init(sf::RenderWindow & _window)
{
	window = &_window;
	maxStringMaxSize = 0;
	nameString = "";
	std::cout << "init " << maxStringMaxSize << std::endl;
}

void PollEventManager::update()
{
	while (window->pollEvent(pollEvent))
	{
		if (pollEvent.type == sf::Event::Closed)
		{
			window->close();
		}
		if (pollEvent.type == sf::Event::TextEntered)
		{
			//std::cout << "ASCII character typed: " << (pollEvent.text.unicode) << std::endl;
			if (pollEvent.text.unicode < 128)
			{
				if (pollEvent.text.unicode == 8)
				{
					if (nameString.size() != 0)
					{
						nameString.pop_back();
					}
				}
				else
				{
					std::cout << "type " << maxStringMaxSize << std::endl;
					if (nameString.size() != maxStringMaxSize)
					{
						if (pollEvent.text.unicode >= 97 && pollEvent.text.unicode <= 122)
						{
							nameString += (char)(pollEvent.text.unicode) - 32;
						}
						if ((pollEvent.text.unicode >= 48 && pollEvent.text.unicode <= 57) || (pollEvent.text.unicode >= 65 && pollEvent.text.unicode <= 90))
						{
							nameString += (char)(pollEvent.text.unicode);
						}
					}

				}

			}
			std::cout << "String : " << nameString << std::endl;
		}
	}
}

void PollEventManager::setStringMaxSiZe(int _value)
{
	maxStringMaxSize = _value;
	std::cout << "define max string value to : " << maxStringMaxSize << std::endl;
	std::cout << "define max string value to : " << _value << std::endl;
}

void PollEventManager::resetString()
{
	nameString.clear();
}

std::string PollEventManager::getString()
{
	return nameString;
}
