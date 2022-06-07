/*
Author: Eduard Schwarzkopf

Description:
	Timer attached to a unit

Parameter(s):
	0: Object - Target
	1: Object - Control object, e.g. a laptop
	2: Number - Seconds to add to total time

Returns:
	Nothing
*/

params ["_target", "_controlPanel", ["_addSeconds", 0]];

if (isServer == false) exitWith {};

_target addEventHandler ["Hit", {
_target setVariable ["shiny_addSeconds", _addSeconds];
	params ["_target", "_unit", "_damage", "_instigator"];

	if (isNil {_unit getVariable "shiny_course"} == false) then {
		[_target, _unit] spawn shiny_fnc_handleTargetHit;
	}
}];

if (_addSeconds isEqualTo 0) then {
	_count = _controlPanel getVariable ["shiny_targetCount", 0];
	_controlPanel setVariable ["shiny_targetCount", (_count + 1), true];
};

_targetList = _controlPanel getVariable ["shiny_targetList", []];
_targetList pushBack _target;	
_controlPanel setVariable ["shiny_targetList", _targetList, true];