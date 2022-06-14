 
class CfgFunctions
{
	class shiny
	{
		class Course
		{
			file = "\shiny_CQBCourses\functions\course";
			class courseInit{};
			class getCourseIdentifier{};
			class formatTime {};
			class courseStart {};
			class courseEnd {};
			class courseReset {};
			class storeTime{};
		};
		class Stopwatch
		{
			file = "\shiny_CQBCourses\functions\stopwatch";
			class stopwatch {};
			class stopStopwatch {};

		};
		class Target
		{
			file = "\shiny_CQBCourses\functions\target";
			class registerTarget {};
			class targetAnimate {};
			class handleTargetHit {};
		};
		class Scoreboard
		{
			file = "\shiny_CQBCourses\functions\scoreboard";
			class initScoreboard {};
			class showScoreboard {};
		};
	};
};