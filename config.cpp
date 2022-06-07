class CfgPatches
{
	class shiny_CQBCourse
	{
		// Meta information for editor
		name = "shiny CQB Course";
		author = "shiny";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.00;
	};
};

#include "defines.hpp"
#include "dialog.hpp"

class CfgFunctions
{
	class shiny
	{
		class CQBCourse
		{
			file = "\shiny_CQBCourse\functions";
			class registerTarget {};
			class handleTargetHit {};
			class courseStart {};
			class courseFinished {};
			class courseReset {};
			class showScoreboard {};
			class stopwatch {};
			class stopStopwatch {};
		};
	};
};
