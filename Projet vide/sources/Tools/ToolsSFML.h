#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>


/////////
/// /// include repetitive functions using the <SFML/Graphics.hpp> library
/////////
class ToolsSFML
{
public:
	ToolsSFML();
	~ToolsSFML();

	#pragma region CREATES

	/////////
	/// /// use the "loadfromfile" function of the SFML to load a specific texture .
	/// /// set the specific texture to a sprite.
	/// /// return the sprite.
	/////////
	static sf::Sprite CreateSpriteFromPath(std::string _PathToTexture);

	/////////
	/// /// use the "loadfromfile" function of the SFML to load a specific texture .
	/// /// set the specific texture to a sprite.
	/// /// return a pointer of the sprite.
	/////////
	static sf::Sprite* CreateSpriteFromPathPointer(std::string _PathToTexture);

	/////////
	/// /// use the "loadfromfile" function of the SFML to load a specific font .
	/// /// set the specific font to a text.
	/// /// return the text.
	/////////
	static sf::Text CreateTextFromPath(std::string _PathToFont);

	/////////
	/// /// use the "loadfromfile" function of the SFML to load a specific font .
	/// /// set the specific font to a text.
	/// /// return a pointer of the text.
	/////////
	static sf::Text* CreateTextFromPathPointer(std::string _PathToFont);

	#pragma endregion CREATES

	#pragma region TEXT

	/////////
	/// /// set The Character Size of the "_TextToUpdate".
	/// /// set The fill Color of the "_TextToUpdate".
	/// /// set The string of the "_TextToUpdate".
	/// /// automatically set the origin of the "_TextToUpdate".
	/// /// set the position of the "_TextToUpdate".
	/// /// return "_TextToUpdate";
	/////////
	static sf::Text* UpdateTextGlobal(sf::Text* _TextToUpdate, int _iCharacterSize, sf::Vector2f _vPosition, sf::Color _colorOfTheText, std::string _stringToWrite);

	/////////
	/// /// set The Character Size of the "_TextToUpdate".
	/// /// set The fill Color of the "_TextToUpdate".
	/// /// set The string of the "_TextToUpdate".
	/// /// automatically set the origin of the "_TextToUpdate".
	/// /// set the position of the "_TextToUpdate".
	/// /// set The outlineColor of the "_TextToUpdate".
	/// /// set The Outline Thickness of the "_TextToUpdate".
	/// /// return "_TextToUpdate";
	/////////
	static sf::Text * UpdateTextGlobalOutline(sf::Text * _TextToUpdate, int _iCharacterSize, sf::Vector2f _vPosition, sf::Color _colorOfTheText, std::string _stringToWrite, sf::Color _OutlineColor, float _OutlineThickness);

	#pragma endregion TEXT

	#pragma region VIEW
	/////////
	/// /// Center the view by the Sprite "_SpriteToFocus".
	/// /// The view can't go further than the edges of the sprite "_SpriteOfTheMap".
	/// /// return the View. 
	/////////
	static sf::View UpdateViewByMapFocus(sf::View _ViewToUpdate, sf::Sprite _SpriteToFocus, sf::Sprite _SpriteOfTheMap);
	/////////
	/// /// Center the view by the Position "_vPosition".
	/// /// The view can't go further than the edges of the sprite "_SpriteOfTheMap".
	/// /// return the View. 
	/////////
	static sf::View UpdateViewByMapPosition(sf::View _ViewToUpdate, sf::Vector2f _vPosition, sf::Sprite _SpriteOfTheMap);

	/////////
	/// Thisfunction update the view by the map in x
	/// Update he view view by the view in y
	/// 
	/////////
	static sf::View UpdateViewByMapX_ByViewY(sf::View _ViewToUpdate, sf::Vector2f _vPosition, sf::Sprite _SpriteOfTheMap);
	/////////
	/// Thisfunction update the parallax by the current map of the level
	/// 
	/////////
	static sf::Sprite UpdateParralaxByLevel(sf::Sprite _SpriteofTheParralax, sf::Sprite _SpriteOfTheMap, float _speedOfParralax);


	////////
	/// EN TEST
	////////
	static void UpdateLoopParralaxByView(sf::Sprite* _SpriteParallaxToLoop, sf::Sprite* _spPlanGame, sf::View *_ViewToRefer, float _speedLoop, sf::Vector2f &_vPosCurrent, sf::Vector2f &_vPosNext, sf::Vector2f _PosPlayer);

	#pragma endregion VIEW

	#pragma region ANGLE

	static double DegToRad(float _degrees);
	static float RadToDeg(double _radians);
	static float GetAngleDegreeFromVector(sf::Vector2f _vector);
	static float GetAngleRadiansBetweenPointAndMouse(sf::Vector2f _pointA, sf::Vector2i _pointB);
	static sf::Vector2f GetDirectionFromAngleDegrees(float _angleDegrees);
	static sf::Vector2f GetDirectionFromAngleRadians(double _angleRadians);

	#pragma endregion ANGLE

	#pragma region STEERING

	static sf::Vector2f Normalize(sf::Vector2f _Vector2fToNormalize);
	static float Magnitude(sf::Vector2f _Vector);
	static sf::Vector2f Truncate(sf::Vector2f _Vector, float _max);

	#pragma endregion STEERING

	#pragma region VERTEX

	static sf::VertexArray * GetLine(sf::Vector2f _startPoint, sf::Vector2f _direction, sf::Color _color);

	static void SetLineBetweenPoints(sf::VertexArray * _vertexArray, sf::Vertex * _vertex, sf::Vector2f _startPoint, sf::Vector2f _destPoint, sf::Color _color);
	#pragma endregion VERTEX


	/////
	/// Prend en compte l'écran
	/////
	static bool PointIsOnView(sf::View _view, sf::Vector2f _Point);
	/////
	/// Prend en compte un sprite
	/////
	static bool PointIsOnMap(sf::Sprite * _spMap, sf::Vector2f _Point);
	/////
	/// Prend en compte une image
	/////
	static bool PointIsOnImage(sf::Image * _Image, sf::Vector2f _Point);
};