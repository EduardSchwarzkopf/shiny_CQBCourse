_unit = _this;
// Stop time
_unit call shiny_fnc_stopStopwatch;
sleep 0.1; // Wait for stopwatch to finish

_time = _unit getVariable ["shiny_StopwatchTime", 0];
_errorSeconds = _unit getVariable["shiny_errorSeconds", 0];

_totalTime = _time + _errorSeconds;
_strTime = _totalTime call shiny_fnc_formatTime;

["TimeTrialEnded", [_strTime]] remoteExec ["BIS_fnc_showNotification", _unit];

_storeTime = {
	params["_course", "_runner", "_totalTime"];

	_scoreList = _course getVariable ["shiny_scoreList", []];
	_index = 0;
	_setRecord = true;
	_isFaster = false;

	for "_i" from 0 to count _scoreList - 1 do {
		_record = _scoreList select _i;
		_unit = _record select 0;
		_time = _record select 1;
		_isFaster = _time > _totalTime;

		if (_isFaster isEqualTo false) then {
			_index = _i;
		};

		if (_runner isEqualTo _unit) then {
			if (_isFaster isEqualTo false) then {
				_setRecord = false;
			} else {
				_scoreList deleteAt _i;
			}
		}
	};

	shiny_fnc_insert = {
		private ["_arr", "_i", "_res"];
		_arr = _this select 0;
		_i = _this select 2;
		_res = [];
		_res append (_arr select [0, _i]);
		_res pushBack (_this select 1);
		_res append (_arr select [_i, count _arr - _i]);
		_res;
	};

	if (_setRecord) then {
		_newScoreList = [_scoreList, [_runner, _totalTime], _index] call shiny_fnc_insert;
		_course setVariable ["shiny_scoreList", _newScoreList, true];

	};
};

_course = _unit getVariable "shiny_course";
[_course, _unit, _totalTime] spawn _storeTime;

// Reset Course
_course spawn shiny_fnc_courseReset;

_unit setVariable ["shiny_course", nil, true];
_course setVariable ["shiny_courseRunner", nil, true];