#include "HostedGame.h"
#include <string>


HostedGame::HostedGame()
{
}

HostedGame::HostedGame(std::string _gameName, bool _isSkin_one, enums::TurretType _turretType)
{
	gameName = _gameName;
	isSkin_one = _isSkin_one;
	turretType = _turretType;
	isSlot2avaible = true;
	isSlot3avaible = true;
	isSlot4avaible = true;
	isSlot5avaible = true;
	emptySlots = 4;

	hostIp = sf::IpAddress::getLocalAddress();

	if (newGameSocket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
	{
		std::cout << "error binding new Socket" << std::endl;
	}
	else
	{
		port = newGameSocket.getLocalPort();
	}


	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");
	gameBox.setSize(sf::Vector2f(650, 50));
	gameBox.setFillColor(sf::Color::Black);
	gameBox.setOutlineColor(sf::Color::White);
	gameBox.setOutlineThickness(2);


	gameNameText.setFont(*font);
	gameNameText.setCharacterSize(50);
	gameNameText.setString(gameName);
	gameNameText.setPosition(0, -5);

	emptySlotsText.setFont(*font);
	emptySlotsText.setCharacterSize(50);
	emptySlotsText.setString(std::to_string(emptySlots));
	emptySlotsText.setPosition(gameNameText.getGlobalBounds().left + gameNameText.getGlobalBounds().width + 50, -5);

	portUsed.setFont(*font);
	portUsed.setCharacterSize(50);
	portUsed.setString(std::to_string((int)port));
	portUsed.setPosition(emptySlotsText.getGlobalBounds().width + emptySlotsText.getGlobalBounds().left + 50, -5);
}


HostedGame::~HostedGame()
{
}

void HostedGame::update()
{
}

void HostedGame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(gameBox, this->getTransform());
	target.draw(gameNameText, this->getTransform());
	target.draw(emptySlotsText, this->getTransform());
	target.draw(portUsed, this->getTransform());

}

sf::FloatRect HostedGame::getGlobalBounds() const
{
	return this->getTransform().transformRect(gameBox.getGlobalBounds());
}

sf::UdpSocket& HostedGame::getSocket()
{
	return newGameSocket;
}

unsigned short HostedGame::getPort()
{
	return port;
}

sf::IpAddress & HostedGame::getHostIp()
{
	return hostIp;
}
