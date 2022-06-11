_lnbEntries = (createDialog ["shiny_CQBScoreboard", false]) displayCtrl 1500;
_scoreList = _this getVariable["shiny_scoreList", []];

for "_i" from 1 to count _scoreList do {
	_item = _scoreList select (_i - 1); 
	_unitName = name (_item select 0); 
	_totalTime = _item select 1;

	_timeFormat = _totalTime call shiny_fnc_formatTime;
	_lnbEntries lnbAddRow [str _i, _unitName, _timeFormat];
};