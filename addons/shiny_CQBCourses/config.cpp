class CfgPatches
{
	class shiny_CQBCourses
	{
		// Meta information for editor
		name = "shiny CQB Courses";
		author = "shiny";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.00;
		units[] = {"shiny_Module_CQB_Course"};
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
			file = "\shiny_CQBCourses\functions";
			class registerTarget {};
			class handleTargetHit {};
			class formatTime {};
			class courseStart {};
			class courseFinished {};
			class courseReset {};
			class showScoreboard {};
			class stopwatch {};
			class stopStopwatch {};
		};
	};
};


class CfgFactionClasses
{
	class NO_CATEGORY;
	class shiny_CQB : NO_CATEGORY {
		displayName = "shiny CQB";
	};
};



class CfgVehicles {

	class Logic;
	class Module_F : Logic {

		class ModuleDescription {
			class AnyPlayer;
			class AnyBrain;
			class EmptyDetector;
		};
	};

	class shiny_Module_CQB_Course : Module_F
	{
		author = "shiny";
        category = "shiny_CQB";
		displayName = "CQB Course";	// Name displayed in the menu
        function =""; // on init module
        scope = 2;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        icon = "";
        class Arguments {
            class Name {
                displayName = "Name";
                description = "Name of the CQB Course";
                typeName = "STRING";
                defaultValue = "";
            };
        };
        class ModuleDescription {
            description = "HELLO OSCHI!";
        };

	};
};