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

	IPhysicsComponentPtr nonCollidingPhysicsPtr =
		make_shared<NonCollidingPhysicsDecorator>(
			make_shared<FixedWidgetPhysics>());
	return make_shared<EntityState>(graphicsPtr, nonCollidingPhysicsPtr);
}

EntityPtr createSlime(std::string const& animationFolder)
{
	auto slime_state = CreateSlimeEnemy(animationFolder);
	EntityPtr slime(new Entity(slime_state));
	return slime;
}