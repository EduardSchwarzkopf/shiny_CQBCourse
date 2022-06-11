params["_startTrigger", "_controlPanel"];

_startTrigger setVariable ["shiny_coursePanel", _controlPanel];

_startTrigger addEventHandler ["Hit", {
	params ["_target"];

	_controlPanel = _target getVariable "shiny_coursePanel";

	_runner = _controlPanel getVariable "shiny_courseRunner";
	if (isNil {_runner} == false && alive _runner) exitWith {
		(["Course already in use by", name _runner] joinString " ") remoteExec ["hint", _runner];
	};

	_unitList = nearestObjects [_target, ["Man"], 20];
	_unit = _unitList select 0;

	["TimeTrialStarted", [str _controlPanel]] call BIS_fnc_showNotification;

	_unit setVariable ["shiny_course", _controlPanel, true];
	_controlPanel setVariable ["shiny_courseRunner", _unit, true];
	_unit setVariable ["shiny_errorSeconds", 0, true];
	_unit setVariable ["shiny_hitCount", 0, true];

	_unit spawn shiny_fnc_stopwatch;
}];