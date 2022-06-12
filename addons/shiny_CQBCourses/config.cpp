class CfgPatches
{
	class shiny_CQBCourses
	{
		// Meta information for editor
		name = "shiny CQB Courses";
		author = "shiny";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game. Note: was disabled on purpose some time late into Arma 2: OA.
		requiredVersion = 1.66;
		units[] = {"shiny_Module_CQB_Course"};
	};
};

#include "defines.hpp"
#include "dialog.hpp"

class CfgFunctions
{
	class shiny
	{
		class CQBCourses
		{
			file = "\shiny_CQBCourses\functions";
			class courseInit{};
			class storeTime{};
			class registerTarget {};
			class handleTargetHit {};
			class formatTime {};
			class courseStart {};
			class courseEnd {};
			class courseReset {};
			class showScoreboard {};
			class stopwatch {};
			class stopStopwatch {};
			class targetAnimate {};
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
	// class Combo;
	
	class Module_F : Logic {

		class ModuleDescription {
			class AnyPlayer;
			class AnyBrain;
			class EmptyDetector;
		};
	};

	class Land_BriefingRoomScreen_01_F;
	class shiny_CQBCourses_Scoreboard: Land_BriefingRoomScreen_01_f
	{
		displayName = "CQB Course Scroreboard";
		author = "shiny";
		hiddenSelectionsTextures[] = { "\shiny_CQBCourses\Data\shiny_cqb_courses_scoreboard.paa" };
		class EventHandlers
        {
			init="(_this select 0) addAction ['a useless action that does nothing', {}];";
        };
	};
	
	class Land_Target_Oval_F;
	class shiny_CQBStartingTarget: Land_Target_Oval_F
	{
		displayName = "CQB Course Start";
		author = "shiny";
		class Attributes
		{
			class shiny_CQBCourses_RunnerPickerType
			{
				displayName = "Pick nearest Unit?"; 
				tooltip = "Course runner should be the neareast Unit to the starting Point? If disabled, the unit hitting the target will be picked"; 
				property = "shiny_CQBCourses_RunnerPickerType"; 
				control = "Checkbox"; 
				expression = "_this setVariable [""shiny_runnerPickerType"",_value,true];";
				defaultValue = "1";
				unique = 0; 
				condition = "(1 - objectBrain) * (1 - objectVehicle)"; 
				typeName = "BOOL"; 
			};
		};
	};

	class All;
	class Static: All
	{
	class Attributes;
	};

	class TargetBase: Static
	{
		class Attributes: Attributes
		{
			// Attribute class, can be anything
			class shiny_CQBCourseAddSeconds
			{
				//--- Mandatory properties
				displayName = "Seconds"; // Name assigned to UI control class Title
				tooltip = "Seconds to add, when target is Hit. Set a number above 0 to give a penalty, when this target is hit. Use negative numbers to give bonus seconds."; // Tooltip assigned to UI control class Title
				property = "shiny_CQBCourses_AddSeconds"; // Unique config property name saved in SQM
				control = "Edit"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

				// Expression called when applying the attribute in Eden and at the scenario start
				// The expression is called twice - first for data validation, and second for actual saving
				// Entity is passed as _this, value is passed as _value
				// %s is replaced by attribute config name. It can be used only once in the expression
				// In MP scenario, the expression is called only on server.
				expression = "_this setVariable ['shiny_CQBCourses_AddSeconds',_value];";

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
		};
	};






	class shiny_Module_CQB_Course : Module_F
	{
		author = "shiny";
        category = "shiny_CQB";
		displayName = "CQB Course";	// Name displayed in the menu
        function ="shiny_fnc_courseInit"; // on init module
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
			// Module specific arguments
			// class Mode: Combo
			// {
			// 	property = "shiny_CBQ_Course_Mode";
			// 	displayName = "Mode"; // Argument label
			// 	tooltip = "Type of Course"; // Tooltip description
			// 	typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			// 	defaultValue = "1"; 
			// 	class Values
			// 	{
			// 		class Single {name = "Solo Course";	value = 1;}; 
			// 		class Squad {name = "Fireteam Course"; value = 2;};
			// 	};
			// };
        };
	};
};
