/*
Author: Eduard Schwarzkopf
Credits: Josef Zemanek

Description:
	Timer attached to a unit

Parameter:
	0: Object - a unit typically a player

Returns:
	Nothing
*/

private ["_t"];
_startTime = time;

_this setVariable ["shiny_RunStopWatch", true, true];
while {_this getVariable ["shiny_RunStopWatch", true] || alive _this isEqualTo false} do {
	_t = time - _startTime;
	sleep 0.01;
};

_this setVariable ["shiny_StopwatchTime", _t, true];