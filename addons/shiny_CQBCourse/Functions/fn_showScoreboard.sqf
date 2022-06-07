_lnbEntries = (createDialog ["shiny_CQBScoreboard", false]) displayCtrl 1500;
_scoreList = _this getVariable["shiny_scoreList", []];

for "_i" from 1 to count _scoreList do {
	_item = _scoreList select (_i - 1); 
	_unitName = name (_item select 0); 
	_totalTime = _item select 1;

	_timeNowFormat = [_totalTime, "MM:SS.MS", TRUE] call BIS_fnc_secondsToString;
	_timeFormat = [_timeNowFormat select 0, _timeNowFormat select 1, _timeNowFormat select 2] joinString ":";
	
	_lnbEntries lnbAddRow [str _i, _unitName, _timeFormat];
};