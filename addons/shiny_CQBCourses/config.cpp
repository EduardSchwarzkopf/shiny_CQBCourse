class CfgPatches
{
	class shiny_CQBCourses
	{
		// Meta information for editor
		name = "shiny CQB Courses";
		author = "Eduard Schwarzkopf";

		requiredVersion = 1.66;
		units[] = {
			"shiny_Module_CQBCourse",
			"shiny_CQBCourses_Scoreboard",
			"shiny_CQBStartingTarget"
		};
	};
};

#include "defines.hpp"
#include "dialog.hpp"

#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"


class CfgFactionClasses
{
	class NO_CATEGORY;
	class shiny_CQB : NO_CATEGORY {
		displayName = "shiny CQB";
	};
};