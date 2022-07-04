class CfgVehicles {

	class Logic;
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
	};
	class Land_Target_Oval_F;
	class shiny_CQBStartingTarget: Land_Target_Oval_F
	{
		displayName = "CQB Course Start";
		author = "shiny";
		hiddenSelectionsTextures[] = { "#(rgb,1,1,1)color(0.56,0.35,0.08,1)" };
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
			class shiny_CQBCourseAddSeconds
			{
				displayName = "Seconds"; 
				tooltip = "Seconds to add, when target is Hit. Set a number above 0 to give a penalty, when this target is hit. Use negative numbers to give bonus seconds.";
				property = "shiny_CQBCourses_AddSeconds"; 
				control = "Edit"; 
				expression = "_this setVariable ['shiny_CQBCourses_AddSeconds',_value];";
				defaultValue = "0";
				unique = 0; 
				validate = "number"; 
				condition = "(1 - objectBrain) * (1 - objectVehicle)"; 
				typeName = "NUMBER"; 
			};
		};
	};

	class shiny_Module_CQBCourse : Module_F
	{
		author = "shiny";
        category = "shiny_CQB";
		displayName = "CQB Course";	// Name displayed in the menu
        function ="shiny_fnc_courseInit"; // on init module
        scope = 2;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
		icon = "\a3\Modules_F_Curator\Data\iconCountdown_ca.paa";
        class Arguments {
            class Name {
                displayName = "Name";
                description = "Name of the CQB Course";
                typeName = "STRING";
                defaultValue = "";
				unique = 1; 
            };
        };
	};
};
