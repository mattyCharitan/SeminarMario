#pragma once
#include "SlimeEntity.h"

using namespace cv;
using namespace std;



EntityStatePtr CreateSlimeEnemy(std::string const& animationFolder)
{
	AnimationPtr animation(new Animation(animationFolder));
	bool isCyclic = true;

	IGraphicsComponentPtr graphicsPtr(
		new SingleAnimationGraphics(animation, isCyclic));

	return make_shared<EntityState>(graphicsPtr, (make_shared<FixedWidgetPhysics>()));
}

EntityPtr createSlime(std::string const& animationFolder)
{
	auto slime_state = CreateSlimeEnemy(animationFolder);
	EntityPtr slime(new Entity(slime_state));
	return slime;
}
