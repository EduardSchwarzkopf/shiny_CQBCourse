
if (isServer == false) exitWith {};

_course = param [0,objNull,[objNull]];
_targetList = param [1,[],[[]]];

_name = _course getVariable ["Name",""];
if (_name isEqualTo "") then {
	_name = _course call BIS_fnc_objectVar;
	_course setVariable ["Name", ["Course-",_name] joinString ""];
};

// handle Targets
_starterTarget = false;

for "_i" from 0 to count _targetList - 1 do {
	_item = _targetList # _i;
	_isStartingTarget = _item isKindOf "shiny_CQB_StartingTarget";
	if (_isStartingTarget) then {
		_starterTarget = _item;
		_course setVariable ["shiny_startingTarget", _item, true];
	};

	if (_item isKindOf "TargetBase" && _isStartingTarget isEqualTo false) then {
		[_course, _item] spawn shiny_fnc_registerTarget;
	};
};

if (_starterTarget isEqualTo false) exitWith {};

_starterTarget setVariable ["shiny_course", _course, true];

_starterTarget addEventHandler ["Hit", {
	private["_unit"];
	_target = _this # 0;

	_course = _target getVariable "shiny_course";
	_prevRunner = _course getVariable ["shiny_courseRunner", nil];

	_useNearestUnit = _target getVariable ["shiny_runnerPickerType", true];
	if (_useNearestUnit isEqualTo false) then {
		_unit = _this # 3; // _instigator
	} else {
		_unitList = nearestObjects [_target, ["Man"], 10];
		_unit = _unitList select 0;
	};

	if (isNil {_unit}) exitWith {};

	if (alive _prevRunner) exitWith {
		(["Course already in use by", name _prevRunner] joinString " ") remoteExec ["hint", _unit];
	};

	[_target, 1] spawn shiny_fnc_targetAnimate;

	_course setVariable ["shiny_courseRunner", _unit, true];
	[_course, _unit] spawn shiny_fnc_courseStart;
}];
