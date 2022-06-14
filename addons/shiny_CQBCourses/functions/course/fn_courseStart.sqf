params["_course", "_unit"];

_courseName = _course getVariable "Name";
["TimeTrialStarted", [_courseName]] call BIS_fnc_showNotification;

_unit setVariable ["shiny_course", _course, true];
_unit setVariable ["shiny_errorSeconds", 0, true];
_unit setVariable ["shiny_hitCount", 0, true];
_unit spawn shiny_fnc_stopwatch;