#include "ScoreEntity.h"
using namespace cv;
using namespace std;



EntityStatePtr CreateScoreState()
{
	IGraphicsComponentPtr graphicsPtr(
		new ScoresGraphics(1.5, 0, FONT_HERSHEY_SIMPLEX));

	IPhysicsComponentPtr physicsPtr = make_shared<FixedWidgetPhysics>();
	return make_shared<EntityState>(graphicsPtr, physicsPtr);
}

EntityPtr CreateScore()
{
	auto score_state = CreateScoreState();
	EntityPtr score(new Entity(score_state));
	return score;
}

