#include "stdafx.h"
#include "Ortus/World.h"
#include "Ortus/BaseComponent.h"

namespace
{
	//---------------------------------------------------------------------------------------------------------
	//	WORLDS
	//---------------------------------------------------------------------------------------------------------
	using WorldA = World<2>;
	using WorldB = World<256>;



	//---------------------------------------------------------------------------------------------------------
	//	COMPONENTS
	//---------------------------------------------------------------------------------------------------------

	// Classic one World Component
	struct ComponentA : public BaseComponent<ComponentA, WorldA>
	{

	};

	// Template Component to support multiple world
	template<typename W>
	struct ComponentT : public BaseComponent<ComponentT<W>, W>
	{

	};
	using ComponentTA = ComponentT<WorldA>;
	using ComponentTB = ComponentT<WorldB>;
	
}

TEST(Components, ComponentId)
{
	EXPECT_EQ(0, ComponentA::GetComponentTypeID());
	EXPECT_EQ(1, ComponentTA::GetComponentTypeID());
	EXPECT_EQ(0, ComponentTB::GetComponentTypeID());
}


