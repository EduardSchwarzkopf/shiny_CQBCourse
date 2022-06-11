params["_target", "_unit"];
	
_addSeconds = _target getVariable["shiny_addSeconds", 0];
_errorSeconds = _unit getVariable["shiny_errorSeconds", 0];

_unit setVariable ["shiny_errorSeconds", (_errorSeconds + _addSeconds), true];

_isHit = _target getVariable ["shiny_isHit", false];
if (_isHit == false && _addSeconds == 0) exitWith {

	_target setVariable ["shiny_isHit", true, true];

	_hitCount = _unit getVariable["shiny_hitCount", 0];
	_newHitCount = _hitCount + 1;
	_unit setVariable ["shiny_hitCount", _newHitCount, true];

	_cp = _unit getVariable "shiny_course";
	// All targets hit?
	if(_cp getVariable "shiny_targetCount" == _newHitCount) then {
		_unit call shiny_fnc_stopStopwatch;
		[_unit, false] spawn shiny_fnc_courseFinished;
	};
};