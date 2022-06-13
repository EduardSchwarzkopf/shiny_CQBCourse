/*
Author: Eduard Schwarzkopf

Description:
	Finishes the course for a unit

Parameter:
	0: Object - Player who runs the course

Returns:
	Nothing

*/

_unit = _this;
// Stop time
_unit call shiny_fnc_stopStopwatch;
sleep 0.1; // Wait for stopwatch to finish

_time = _unit getVariable ["shiny_StopwatchTime", 0];
_errorSeconds = _unit getVariable["shiny_errorSeconds", 0];

_totalTime = _time + _errorSeconds;
_strTime = _totalTime call shiny_fnc_formatTime;

["TimeTrialEnded", [_strTime]] remoteExec ["BIS_fnc_showNotification", _unit];

_course = _unit getVariable "shiny_course";
[_course, _unit, _totalTime] remoteExec ["shiny_fnc_storeTime", 2];

// Reset Course
_course spawn shiny_fnc_courseReset;

_unit setVariable ["shiny_course", nil, true];
_course setVariable ["shiny_courseRunner", nil, true];