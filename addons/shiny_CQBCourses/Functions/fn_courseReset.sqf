params["_controlPanel"];

_list = _controlPanel getVariable ["shiny_targetList", []];

// Reset all Targets
{
	_x setVariable ["shiny_isHit", false, true];
} forEach _list;
