#pragma once

#include "PhysicsEngine.h"
#include <iostream>
#include <iomanip>

namespace PhysicsEngine
{
	class CompoundShape : public DynamicActor
	{
	public:
		CompoundShape(const PxTransform& pose = PxTransform(PxIdentity), PxVec3 dimensions = PxVec3(0.5f, 0.5f, 0.5f), PxReal density = 1.0f)
			: DynamicActor(pose)
		{
			CreateShape(PxBoxGeometry(dimensions), density);
			CreateShape(PxBoxGeometry(dimensions), density);
		}
	};

	class CapsuleWheel : public DynamicActor
	{
	public:
		CapsuleWheel(const PxTransform& pose = PxTransform(PxIdentity), PxVec2 dimensions = PxVec2(0.5f, 1.0f), PxReal density = 1.0f)
			: DynamicActor(pose)
		{
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
			CreateShape(PxCapsuleGeometry(dimensions.x, dimensions.y), density);
		}
	};
}