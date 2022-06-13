params["_course"];

_list = _course getVariable ["shiny_targetList", []];
_starterTarget = _course getVariable "shiny_startingTarget";

[_starterTarget, 0] spawn shiny_fnc_targetAnimate;
// Reset all Targets
{
	_x setVariable ["shiny_isHit", false, true];
} forEach _list;
