params["_course", "_runner", "_totalTime"];

if (!isServer) exitWith {}; // Just to be sure

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

_shiny_fnc_insert = {
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
	_newScoreList = [_scoreList, [_runner, _totalTime], _index] call _shiny_fnc_insert;
	_name = _course getVariable "Name";
	_varName = ["shiny_CQBCourses_Score_", _name] joinString "";

	profileNamespace setVariable [_varName, _newScoreList, true];
};