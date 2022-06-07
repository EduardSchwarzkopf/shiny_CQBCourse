params["_unit", "_canceled"];

_time = _unit getVariable ["shiny_StopwatchTime", 0];
_errorSeconds = _unit getVariable["shiny_errorSeconds", 0];

_totalTime = _time + _errorSeconds;

_result = "finished";
if (_canceled) then {
	_result = "canceled";
};

storeTime = {
	params["_cp", "_runner", "_totalTime"];

	private _scoreList = _cp getVariable ["shiny_scoreList", []];
	private _index = 0;
	private _isSet = false;
	private _setRecord = true;

	for "_i" from 0 to count _scoreList - 1 do {
		_record = _scoreList select _i;
		_unit = _record select 0;
		_time = _record select 1;
		_isFaster = _time > _totalTime;

		if (_isSet isEqualTo false && _isFaster) then {
			_index = _i;
			_isSet = true;
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
		_cp setVariable ["shiny_scoreList", _newScoreList, true];

	}

};

_cp = _unit getVariable "shiny_course";
[_cp, _unit, _totalTime] spawn storeTime;

// Reset Course
_cp spawn shiny_fnc_courseReset;

_unit setVariable ["shiny_course", nil, true];
_cp setVariable ["shiny_courseRunner", nil, true];