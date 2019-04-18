
#include "ToolsSFML.h"

#ifndef PI
#define PI 3.14159265358979323846264338327
#endif

#define DEBUG std::cout << "debug" << std::endl;


ToolsSFML::ToolsSFML()
{
}

ToolsSFML::~ToolsSFML()
{
}

#pragma region CREATES

sf::Sprite ToolsSFML::CreateSpriteFromPath(std::string _PathToTexture)
{
	// create a pointer to a texture
	sf::Texture *texture = new sf::Texture;

	//load the texture from the file & make an error management
	if (!texture->loadFromFile(_PathToTexture))
	{
		std::cout << "Fail To Dowload The texture" << std::endl;
		//exit(EXIT_FAILURE);
	}
	sf::Sprite sprite;
	sprite.setTexture(*texture); // apply the texture to a sprite
	return sprite; // return the sprite
}

sf::Sprite* ToolsSFML::CreateSpriteFromPathPointer(std::string _PathToTexture)
{
	// create a pointer to a texture
	sf::Texture *texture = new sf::Texture;

	//load the texture from the file & make an error management
	if (!texture->loadFromFile(_PathToTexture))
	{
		std::cout << "Fail To Dowload The texture" << std::endl;
		//exit(EXIT_FAILURE);
	}
	sf::Sprite *sprite = new sf::Sprite;
	sprite->setTexture(*texture); // apply the texture to a sprite
	return sprite; // return the sprite
}

sf::Text ToolsSFML::CreateTextFromPath(std::string _PathToFont)
{
	// create a pointer to a font
	sf::Font *font = new sf::Font;

	//load the font from the file & make a verification
	if (!font->loadFromFile(_PathToFont))
	{
		std::cout << "Fail To Download the font" << std::endl;
		//exit(EXIT_FAILURE);
	}
	sf::Text text;
	text.setFont(*font); // apply the font to a text
	return text; // return the text
}

sf::Text* ToolsSFML::CreateTextFromPathPointer(std::string _PathToFont)
{
	// create a pointer to a font
	sf::Font *font = new sf::Font;

	//load the font from the file & make a verification
	if (!font->loadFromFile(_PathToFont))
	{
		std::cout << "Fail To Download the font" << std::endl;
		//exit(EXIT_FAILURE);
	}
	sf::Text *text = new sf::Text();
	text->setFont(*font); // apply the font to a text
	return text; // return the text
}

#pragma endregion CREATES

#pragma region VIEW

sf::View ToolsSFML::UpdateViewByMapFocus(sf::View _ViewToUpdate, sf::Sprite _SpriteToFocus, sf::Sprite _SpriteOfTheMap)
{
	
	sf::Vector2f vCenterCamera; // use to center the camera
	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (horizontal(x)*/
	if (_SpriteToFocus.getPosition().x > _ViewToUpdate.getSize().x / 2 && _SpriteToFocus.getPosition().x < _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _SpriteToFocus.getPosition().x;
	}
	/*left edge*/
	else if (_SpriteToFocus.getPosition().x <= (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _ViewToUpdate.getSize().x / 2;
	}
	/*right edge*/
	else if (_SpriteToFocus.getPosition().x >= (_SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2)))
	{
		vCenterCamera.x = _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2);
	}

	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (vertical(y)*/
	if (_SpriteToFocus.getPosition().y > _ViewToUpdate.getSize().y / 2 && _SpriteToFocus.getPosition().y < _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2))
	{
		vCenterCamera.y = _SpriteToFocus.getPosition().y;
	}
	/*up edge*/
	else if (_SpriteToFocus.getPosition().y <= (_ViewToUpdate.getSize().y / 2))
	{
		vCenterCamera.y = _ViewToUpdate.getSize().y / 2;
	}
	/*down edge*/
	else if (_SpriteToFocus.getPosition().y >= (_SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2)))
	{
		vCenterCamera.y = _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2);
	}
	_ViewToUpdate.setCenter(vCenterCamera);
	return _ViewToUpdate;
}

sf::View ToolsSFML::UpdateViewByMapPosition(sf::View _ViewToUpdate, sf::Vector2f _vPosition, sf::Sprite _SpriteOfTheMap)
{
	sf::Vector2f vCenterCamera; // use to center the camera
	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (horizontal(x)*/
	if (_vPosition.x > _ViewToUpdate.getSize().x / 2 && _vPosition.x < _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _vPosition.x;
	}
	/*left edge*/
	else if (_vPosition.x <= (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _ViewToUpdate.getSize().x / 2;
	}
	/*right edge*/
	else if (_vPosition.x >= (_SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2)))
	{
		vCenterCamera.x = _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2);
	}

	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (vertical(y)*/
	if (_vPosition.y > _ViewToUpdate.getSize().y / 2 && _vPosition.y < _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2))
	{
		vCenterCamera.y = _vPosition.y;
	}
	/*up edge*/
	else if (_vPosition.y <= (_ViewToUpdate.getSize().y / 2))
	{
		vCenterCamera.y = _ViewToUpdate.getSize().y / 2;
	}
	/*down edge*/
	else if (_vPosition.y >= (_SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2)))
	{
		vCenterCamera.y = _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2);
	}
	_ViewToUpdate.setCenter(vCenterCamera);

	//std::cout << "VIEW CENTER X : " << _ViewToUpdate.getCenter().x << "VIEW CENTER Y : " << _ViewToUpdate.getCenter().y << std::endl;
	return _ViewToUpdate;
}

sf::View ToolsSFML::UpdateViewByMapX_ByViewY(sf::View _ViewToUpdate, sf::Vector2f _vPosition, sf::Sprite _SpriteOfTheMap)
{
	sf::Vector2f vCenterCamera; // use to center the camera

	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (horizontal(x)*/
	if (_vPosition.x > _ViewToUpdate.getSize().x / 2 && _vPosition.x < _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _vPosition.x;
	}
	/*left edge*/
	else if (_vPosition.x <= (_ViewToUpdate.getSize().x / 2))
	{
		vCenterCamera.x = _ViewToUpdate.getSize().x / 2;
	}
	/*right edge*/
	else if (_vPosition.x >= (_SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2)))
	{
		vCenterCamera.x = _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2);
	}

	/*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (vertical(y)*/
	//if (_vPosition.y > _ViewToUpdate.getSize().y / 2 && _vPosition.y < _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2))
	//{
	//	vCenterCamera.y = _vPosition.y;
	//}
	///*up edge*/
	//else if (_vPosition.y <= (_ViewToUpdate.getSize().y / 2))
	//{
	//	vCenterCamera.y = _ViewToUpdate.getSize().y / 2;
	//}
	///*down edge*/
	//else if (_vPosition.y >= (_SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2)))
	//{
	//	vCenterCamera.y = _SpriteOfTheMap.getGlobalBounds().height - (_ViewToUpdate.getSize().y / 2);
	//}

	vCenterCamera.y = _vPosition.y;
	_ViewToUpdate.setCenter(vCenterCamera);

	//std::cout << "VIEW CENTER X : " << _ViewToUpdate.getCenter().x << "VIEW CENTER Y : " << _ViewToUpdate.getCenter().y << std::endl;
	return _ViewToUpdate;
}

sf::Sprite ToolsSFML::UpdateParralaxByLevel(sf::Sprite _SpriteofTheParralax, sf::Sprite _SpriteOfTheMap, float _speedOfParralax)
{
//	sf::Vector2f vCenterCamera; // use to center the camera
///*check if the "_SpriteToFocus" is at a half view distance of the edges of the "_SpriteOfTheMap" (horizontal(x)*/
//	if (_vPosition.x > _ViewToUpdate.getSize().x / 2 && _vPosition.x < _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2))
//	{
//		vCenterCamera.x = _vPosition.x;
//	}
//	/*left edge*/
//	else if (_vPosition.x <= (_ViewToUpdate.getSize().x / 2))
//	{
//		vCenterCamera.x = _ViewToUpdate.getSize().x / 2;
//	}
//	/*right edge*/
//	else if (_vPosition.x >= (_SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2)))
//	{
//		vCenterCamera.x = _SpriteOfTheMap.getGlobalBounds().width - (_ViewToUpdate.getSize().x / 2);
//	}
	return sf::Sprite();
}

void ToolsSFML::UpdateLoopParralaxByView( sf::Sprite* _SpriteParallaxToLoop,sf::Sprite* _spPlanGame, sf::View *_ViewToRefer, float _speedLoop, sf::Vector2f &_vPosCurrent, sf::Vector2f &_vPosNext, sf::Vector2f _PosPlayer)
{
	//INIT VAR
	sf::Vector2f p_vPosTopLeftView; // correspond a la position topLeft de la view

	//JE CHOPE LA POSITION TOP VIEW DE LA VIEW
	p_vPosTopLeftView = sf::Vector2f(
		_ViewToRefer->getCenter().x - _ViewToRefer->getSize().x / 2,
		_ViewToRefer->getCenter().y - _ViewToRefer->getSize().y / 2);

	//EN Y
	///pour l'instant je laisse le y a la position de la vue
	_vPosCurrent.y = p_vPosTopLeftView.y;
	_vPosNext.y = _vPosCurrent.y;

	//EN X
	///JE DOIS BOUGER SEULEMENT SI LA CAMERA BOUGE
	
	///UPDATE DE LA POSIITON
	//VU QUE C'EST UN BOUCLAGE JE PEUT ME PREMETTRE DE DEFINIR SEULEMENT UNE SPEED POUR BOUGER ET NE PAS PRENDRE EN COMPOTE LES COTES DU PARALLAX 
	//PAR CONTRE JE DOIS PRENDRE EN COMPTE LES CÔTES DE LA VU
	//SI LE PLAN DE JEU ARRETE DE DEFILER DANS LE PARRALAX DOIT AUSSI ARRETER DE DEFILER
	/////////////////////////////////////////////////////////////////////
	//QUAND LE PLAYER A PASSE LA GAUCHE  && n'est pas encore a droite de l'ecran
	//CAMERA COLLE AU COTE DROIT DU PLAN DE JEU
	if (_PosPlayer.x > _spPlanGame->getGlobalBounds().left + _ViewToRefer->getSize().x / 2
		&& _PosPlayer.x < (_spPlanGame->getGlobalBounds().left + _spPlanGame->getGlobalBounds().width) - _ViewToRefer->getSize().x / 2)
	{
		_vPosCurrent.x -= _speedLoop;
	}

	/////////////////////////////////////////////////////////////////////

	///SECURITE AVEC PRISE EN COMPTE DE LA VIEW
	if (_vPosCurrent.x < p_vPosTopLeftView.x - _SpriteParallaxToLoop->getGlobalBounds().width)
	{
		_vPosCurrent.x = p_vPosTopLeftView.x;
		_vPosNext.x = p_vPosTopLeftView.x + _SpriteParallaxToLoop->getGlobalBounds().width;
	}
	else if (_vPosCurrent.x > p_vPosTopLeftView.x)
	{
		_vPosCurrent.x = p_vPosTopLeftView.x - _SpriteParallaxToLoop->getGlobalBounds().width;
		_vPosNext.x = p_vPosTopLeftView.x;
	}

	//la position next est égale a la position current en x + la largeur du background
	_vPosNext.x = _vPosCurrent.x + _SpriteParallaxToLoop->getGlobalBounds().width;
	//std::cout << "TOOLS : CURRENT_X : " << _vPosCurrent.x << " CURRENT_Y : " << _vPosCurrent.y;
	//std::cout << " NEXT_X : " << _vPosNext.x << " NEXT_Y : " << _vPosNext.y << std::endl;

}

#pragma endregion VIEW

#pragma region TEXT

sf::Text* ToolsSFML::UpdateTextGlobal(sf::Text* _TextToUpdate, int _iCharacterSize, sf::Vector2f _vPosition, sf::Color _colorOfTheText, std::string _stringToWrite)
{
	_TextToUpdate->setCharacterSize(_iCharacterSize);
	_TextToUpdate->setFillColor(_colorOfTheText);
	_TextToUpdate->setString(_stringToWrite);
	_TextToUpdate->setOrigin(_TextToUpdate->getGlobalBounds().width / 2, _TextToUpdate->getGlobalBounds().height / 2);
	_TextToUpdate->setPosition(_vPosition);
	return _TextToUpdate;
}

sf::Text* ToolsSFML::UpdateTextGlobalOutline(sf::Text* _TextToUpdate, int _iCharacterSize, sf::Vector2f _vPosition, sf::Color _colorOfTheText, std::string _stringToWrite, sf::Color _OutlineColor, float _OutlineThickness)
{
	_TextToUpdate->setCharacterSize(_iCharacterSize);
	_TextToUpdate->setFillColor(_colorOfTheText);
	_TextToUpdate->setString(_stringToWrite);
	_TextToUpdate->setOrigin(_TextToUpdate->getGlobalBounds().width / 2, _TextToUpdate->getGlobalBounds().height / 2);
	_TextToUpdate->setPosition(_vPosition);
	_TextToUpdate->setOutlineColor(_OutlineColor);
	_TextToUpdate->setOutlineThickness(_OutlineThickness);
	return _TextToUpdate;
}

#pragma endregion TEXT

#pragma region ANGLE

double ToolsSFML::DegToRad(float _degrees)
{
	return (_degrees * PI) / 180;
}

float ToolsSFML::RadToDeg(double _radians)
{
	return _radians * (180 / PI);
}

float ToolsSFML::GetAngleDegreeFromVector(sf::Vector2f _vector)
{
	float angleRadians = atan2(_vector.y, _vector.x);

	return RadToDeg(angleRadians);
}

float ToolsSFML::GetAngleRadiansBetweenPointAndMouse(sf::Vector2f _pointA, sf::Vector2i _pointB)
{
	return atan2(_pointB.y - _pointA.y, _pointB.x - _pointA.x);
}

sf::Vector2f ToolsSFML::GetDirectionFromAngleRadians(double _angleRadians)
{
	sf::Vector2f direction;

	direction.x = cos(_angleRadians);
	direction.y = sin(_angleRadians);

	return direction;
}

sf::Vector2f ToolsSFML::GetDirectionFromAngleDegrees(float _angleDegrees)
{
	return GetDirectionFromAngleRadians(ToolsSFML::DegToRad(_angleDegrees));
}

#pragma endregion ANGLE

#pragma region STEERING

sf::Vector2f ToolsSFML::Normalize(sf::Vector2f _Vector2fToNormalize)
{
	double lenght = Magnitude(_Vector2fToNormalize);
	//cout << "Magnitude : " << lenght;

	sf::Vector2f newVector2f;
	newVector2f.x = _Vector2fToNormalize.x / lenght;
	newVector2f.y = _Vector2fToNormalize.y / lenght;
	//cout << "VectorNormalized.x : " << newVector2f.x << " VectorNormalized.y : " << newVector2f.y;
	return newVector2f;
}

float ToolsSFML::Magnitude(sf::Vector2f _Vector)
{
	return sqrt(_Vector.x*_Vector.x + _Vector.y*_Vector.y);
}

sf::Vector2f ToolsSFML::Truncate(sf::Vector2f _Vector, float _max)
{
	if (Magnitude(_Vector) > _max)
	{
		_Vector = Normalize(_Vector);
		_Vector.x *= _max;
		_Vector.y *= _max;
	}
	return _Vector;
}

#pragma endregion STEERING

#pragma region VERTEX
sf::VertexArray * ToolsSFML::GetLine(sf::Vector2f _startPoint, sf::Vector2f _direction, sf::Color _color)
{
	sf::VertexArray* vertexArray = new sf::VertexArray(sf::Lines);

	//1rst vertex
	sf::Vertex* newVertex = new sf::Vertex(_startPoint, _color);
	vertexArray->append(*newVertex);

	//2nd vertex
	newVertex->position.x = _startPoint.x + _direction.x;
	newVertex->position.y = _startPoint.y + _direction.y;

	vertexArray->append(*newVertex);

	return vertexArray;
}

void ToolsSFML::SetLineBetweenPoints(sf::VertexArray * _vertexArray, sf::Vertex * _vertex, sf::Vector2f _startPoint, sf::Vector2f _destPoint, sf::Color _color)
{
	_vertexArray->clear();
	_vertexArray->setPrimitiveType(sf::Lines);

	//1rst
	_vertex->color = _color;
	_vertex->position = _startPoint;

	_vertexArray->append(*_vertex);

	//2nd
	_vertex->position = _destPoint;

	_vertexArray->append(*_vertex);
}
#pragma endregion VERTEX

//bool ToolsSFML::PointIsOnScreen(sf::RenderWindow *_window, sf::Vector2f _Point)
//{
//
//	if (_Point.x < 0
//		|| _Point.x > _window->getSize().x 
//		|| _Point.y < 0
//		|| _Point.y > _window->getSize().y)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}

bool ToolsSFML::PointIsOnView(sf::View _view, sf::Vector2f _Point)
{
	//CALCUL PAR RAPPORT AU CENTRE ET A LA SIZE DE LA VIEW

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		DEBUG;
	}
	if(_Point.x < _view.getCenter().x - _view.getSize().x / 2
		|| _Point.x > _view.getCenter().x + _view.getSize().x / 2
		|| _Point.y < _view.getCenter().y - _view.getSize().y / 2
		|| _Point.y > _view.getCenter().y + _view.getSize().y / 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ToolsSFML::PointIsOnMap(sf::Sprite * _spMap, sf::Vector2f _Point)
{
	if (_Point.x < _spMap->getGlobalBounds().left
		|| _Point.x > _spMap->getGlobalBounds().left + _spMap->getGlobalBounds().width
		|| _Point.y < _spMap->getGlobalBounds().top
		|| _Point.y > _spMap->getGlobalBounds().top + _spMap->getGlobalBounds().height)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ToolsSFML::PointIsOnImage(sf::Image * _Image, sf::Vector2f _Point)
{
	if (_Point.x < 0
		|| _Point.x > _Image->getSize().x
		|| _Point.y < 0
		|| _Point.y > _Image->getSize().y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

