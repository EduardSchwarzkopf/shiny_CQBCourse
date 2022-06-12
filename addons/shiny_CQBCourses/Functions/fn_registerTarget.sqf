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

params ["_course", "_target"];

if ((_target getVariable ["shiny_CQB_Course_AddSeconds",0]) isEqualTo 0) then {
	_targetList = _course getVariable ["shiny_targetList", []];
	_targetList pushBack _target;
	_course setVariable ["shiny_targetList", _targetList, true];
};

_target addEventHandler ["Hit", {
	params ["_target", "_unit"];

	if (isNil {_unit getVariable "shiny_course"} == false) then {
		[_target, _unit] spawn shiny_fnc_handleTargetHit;
	}
}];