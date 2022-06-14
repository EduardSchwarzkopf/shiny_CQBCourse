/*
Author: Eduard Schwarzkopf

Description:
	Finishes the course for a unit

Parameter:
	0: Object (shiny_Module_CQBCourse)
	1: Object - Anything that should have an addAction to show the Scoreboard

Returns:
	Nothing

*/

params["_course", "_scoreboard"];
if !(typeOf _course isEqualTo "shiny_Module_CQBCourse") exitWith {}; // Not a shiny CQB Course, exit

_name = _course getVariable "Name";
_title = [_name, "Scoreboard"] joinString " ";

_scoreboard addAction [
	_title,	
	{
		_name = _this select 3;
		_name spawn shiny_fnc_showScoreboard;
	},
	_name,		// arguments
	1,			// priority
	true,		// showWindow
	true,		// hideOnUse
	"",			// shortcut
	"true", 	// condition
	5			// radius
];