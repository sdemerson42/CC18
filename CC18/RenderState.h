#pragma once

#include "SFML\Graphics.hpp"
#include <string>
#include "AutoList.h"

struct RenderState : public AutoList<RenderState>
{
	enum class RenderLayer
	{
		Back, Mid, Front
	};
	RenderState(RenderLayer layer = RenderLayer::Back, const std::string &tName = "",
		sf::PrimitiveType primType = sf::PrimitiveType::Quads, sf::Vector2f tCoords = sf::Vector2f{ 0,0 }, sf::Vector2f size = sf::Vector2f{},
		bool active = true, float scale = 1.0f) :
		layer{ layer }, textureName{ tName }, primitive{ primType }, textureCoords{ tCoords }, size{ size }, active{ active },
		scale{ scale }
	{}
	
	RenderLayer layer;
	std::string textureName;
	sf::PrimitiveType primitive;
	sf::Vector2f textureCoords;
	sf::Vector2f size;
	bool active;
	float scale;
	sf::Vector2f position;
};