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

class Cfg3DEN
{
	// Configuration of all objects
	class Object
	{
		// Categories collapsible in "Edit Attributes" window
		class AttributeCategories
		{
			// Category class, can be anything
			class shiny_CQB
			{
				displayName = "shiny CQB"; // Category name visible in Edit Attributes window
				collapsed = 0; // When 1, the category is collapsed by default
				class Attributes
				{
					// Attribute class, can be anything
					class shiny_CQBCourseAddSeconds
					{
						//--- Mandatory properties
						displayName = "Seconds"; // Name assigned to UI control class Title
						tooltip = "Seconds to add, when target is Hit. Set a number above 0 to give a penalty, when this target is hit. Use negative numbers to give bonus seconds."; // Tooltip assigned to UI control class Title
						property = "shiny_CQBCourseAddSeconds"; // Unique config property name saved in SQM
						control = "Edit"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

						// Expression called when applying the attribute in Eden and at the scenario start
						// The expression is called twice - first for data validation, and second for actual saving
						// Entity is passed as _this, value is passed as _value
						// %s is replaced by attribute config name. It can be used only once in the expression
						// In MP scenario, the expression is called only on server.
						expression = "_this setVariable ['%s',_value];";

						// Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
						// Entity (unit, group, marker, comment etc.) is passed as _this
						// Returned value is the default value
						// Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
						// Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
						defaultValue = "0";

						//--- Optional properties
						unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
						validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
						condition = "(1 - objectBrain) * (1 - objectVehicle)"; // Condition for attribute to appear (see the table below)
						typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
					};
					class shiny_CQBCourseIsStarter
					{
						//--- Mandatory properties
						displayName = "Is Starter"; // Name assigned to UI control class Title
						tooltip = "Should hitting this target start the course?"; // Tooltip assigned to UI control class Title
						property = "shiny_CQBCourseIsStarter"; // Unique config property name saved in SQM
						control = "Checkbox"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

						// Expression called when applying the attribute in Eden and at the scenario start
						// The expression is called twice - first for data validation, and second for actual saving
						// Entity is passed as _this, value is passed as _value
						// %s is replaced by attribute config name. It can be used only once in the expression
						// In MP scenario, the expression is called only on server.
						expression = "_this setVariable [""shiny_CQBCourseIsStarter"",_value,true)];";

						// Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
						// Entity (unit, group, marker, comment etc.) is passed as _this
						// Returned value is the default value
						// Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
						// Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
						defaultValue = "0";

						//--- Optional properties
						unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
						validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
						condition = "(1 - objectBrain) * (1 - objectVehicle)"; // Condition for attribute to appear (see the table below)
						typeName = "BOOL"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
					};
				};
			};
		};
	};
};