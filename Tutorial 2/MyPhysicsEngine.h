#pragma once

#include "BasicActors.h"
#include "CompoundActors.h"
#include <iostream>
#include <iomanip>

namespace PhysicsEngine
{
	using namespace std;

	//a list of colours: Circus Palette
	static const PxVec3 color_palette[] = {PxVec3(46.f/255.f,9.f/255.f,39.f/255.f),PxVec3(217.f/255.f,0.f/255.f,0.f/255.f),
		PxVec3(255.f/255.f,45.f/255.f,0.f/255.f),PxVec3(255.f/255.f,140.f/255.f,54.f/255.f),PxVec3(4.f/255.f,117.f/255.f,111.f/255.f)};

	//pyramid vertices
	static PxVec3 pyramid_verts[] = {PxVec3(0,5,0), PxVec3(1,0,0), PxVec3(-1,0,0), PxVec3(0,0,1), PxVec3(0,0,-1)};
	//pyramid triangles: a list of three vertices for each triangle e.g. the first triangle consists of vertices 1, 4 and 0
	//vertices have to be specified in a counter-clockwise order to assure the correct shading in rendering
	static PxU32 pyramid_trigs[] = {1, 4, 0, 3, 1, 0, 2, 3, 0, 4, 2, 0, 3, 2, 1, 2, 4, 1};

	class Pyramid : public ConvexMesh
	{
	public:
		Pyramid(PxTransform pose=PxTransform(PxIdentity), PxReal density=1.f) :
			ConvexMesh(vector<PxVec3>(begin(pyramid_verts),end(pyramid_verts)), pose, density)
		{
		}
	};

	class PyramidStatic : public TriangleMesh
	{
	public:
		PyramidStatic(PxTransform pose=PxTransform(PxIdentity)) :
			TriangleMesh(vector<PxVec3>(begin(pyramid_verts),end(pyramid_verts)), vector<PxU32>(begin(pyramid_trigs),end(pyramid_trigs)), pose)
		{
		}
	};

	///Custom scene class
	class MyScene : public Scene
	{
		Plane* plane;
		Box* box;
		//CompoundShape* box2;
		//CapsuleWheel* wheel;
		//ConvexMesh* pyramid;
		Wedge* wedge;
		Hexagon* hex;

	public:
		///A custom scene class
		void SetVisualisation()
		{
			px_scene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 1.0f);
			px_scene->setVisualizationParameter(PxVisualizationParameter::eCOLLISION_SHAPES, 1.0f);
		}

		//Custom scene initialisation
		virtual void CustomInit() 
		{
			SetVisualisation();			

			CreateMaterial(0.94, 0.40, 0.1);
			CreateMaterial(1.10, 0.15, 0.2);
			CreateMaterial(0.55, 0.40, 0.6);
			CreateMaterial(0.78, 0.42, 0.2);
			CreateMaterial(0.04, 0.04, 0.1);
			CreateMaterial(0.38, 0.20, 0.4);
			CreateMaterial(0.10, 0.03, 0.1);
			CreateMaterial(0.10, 0.08, 0.2);

			plane = new Plane();
			plane->Color(PxVec3(210.f/255.f,210.f/255.f,210.f/255.f));
			Add(plane);

			hex = new Hexagon(1.0f, 10.0f, PxTransform(PxVec3(0.0f, 0.0f, 0.0f), PxQuat(0.0f, PxVec3(0.0f, 0.0f, 0.0f))));
			hex->mesh->Color(color_palette[2], 0);
			hex->mesh->Material(GetMaterial(1));
			Add(hex->mesh);

			wedge = new Wedge(5.0f, 10.0f, 10.0f, PxTransform(PxVec3(0.0f, 10.0f, 0.0f), PxQuat(0.0f, PxVec3(0.0f, 0.0f, 0.0f))));
			wedge->mesh->Color(color_palette[0], 0);
			wedge->mesh->Material(GetMaterial(1));
			Add(wedge->mesh);

			/*pyramid = new Pyramid(PxTransform(PxVec3(1.0f, 0.0f, 0.0f)));
			pyramid->Color(color_palette[0], 0);
			Add(pyramid);*/

			/*wheel = new CapsuleWheel(PxTransform(PxVec3(0.0f, 10.0f, 0.0f)));
			wheel->GetShape(0)->setLocalPose(PxTransform(PxVec3(0.0f, 0.0f, 2.0f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(1)->setLocalPose(PxTransform(PxVec3(0.0f, 0.0f, -2.0f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(2)->setLocalPose(PxTransform(PxVec3(0.0f, 2.0f, 0.0f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(3)->setLocalPose(PxTransform(PxVec3(0.0f, -2.0f, 0.0f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(4)->setLocalPose(PxTransform(PxVec3(0.0f, 1.25f, -1.25f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(5)->setLocalPose(PxTransform(PxVec3(0.0f, -1.25f, -1.25f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(6)->setLocalPose(PxTransform(PxVec3(0.0f, 1.25f, 1.25f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			wheel->GetShape(7)->setLocalPose(PxTransform(PxVec3(0.0f, -1.25f, 1.25f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			Add(wheel);*/

			/*box2 = new CompoundShape(PxTransform(PxVec3(.0f,10.f,.0f)));
			box2->Color(color_palette[0], 0);
			box2->Color(color_palette[1], 1);
			box2->GetShape(0)->setLocalPose(PxTransform(PxVec3(1.0f, 0.0f, 0.0f), PxQuat(45.0f, PxVec3(1.0f, 0.0f, 0.0f))));
			Add(box2);*/

			box = new Box(PxTransform(PxVec3(2.0f, 100.0f, 2.0f), PxQuat(0.0f, PxVec3(0.0f, 0.0f, 0.0f))));
			box->Color(color_palette[1], 0);
			box->Material(GetMaterial(3));
			Add(box);
		}

		//Custom udpate function
		virtual void CustomUpdate() 
		{
		}
	};
}
