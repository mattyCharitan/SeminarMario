#include "LifeEntity.h"
using namespace cv;
using namespace std;



EntityStatePtr CreatelivesState(std::string const& animationFolder)
{
	AnimationPtr animation(new Animation(animationFolder));
	IGraphicsComponentPtr graphicsPtr(new LivesGraphics(Frame(animationFolder+"/heart.png")));

	IPhysicsComponentPtr physicsPtr = make_shared<FixedWidgetPhysics>();
	return make_shared<EntityState>(graphicsPtr, physicsPtr);
}

EntityPtr Createlives(std::string const& animationFolder)
{
	auto life_state = CreatelivesState(animationFolder);
	EntityPtr life(new Entity(life_state));
	return life;
}
