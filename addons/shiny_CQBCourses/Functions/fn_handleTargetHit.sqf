params["_target", "_unit"];

_addSeconds = _target getVariable ["shiny_CQB_Course_AddSeconds", 0];;
_errorSeconds = _unit getVariable["shiny_errorSeconds", 0];

_unit setVariable ["shiny_errorSeconds", (_errorSeconds + _addSeconds), true];

_isHit = _target getVariable ["shiny_isHit", false];
if (_isHit isEqualTo false && _addSeconds isEqualTo 0) exitWith {

	_target setVariable ["shiny_isHit", true, true];

	_hitCount = _unit getVariable["shiny_hitCount", 0];
	_newHitCount = _hitCount + 1;
	_unit setVariable ["shiny_hitCount", _newHitCount, true];

	_course = _unit getVariable "shiny_course";
	_targetList = _course getVariable ["shiny_targetList", []];

	// All targets hit?
	if(count _targetList == _newHitCount) then {
		_unit spawn shiny_fnc_courseEnd;
	};
};