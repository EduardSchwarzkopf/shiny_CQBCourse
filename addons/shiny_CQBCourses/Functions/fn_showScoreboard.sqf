/*
Author: Eduard Schwarzkopf

Description:
	Shows the Scoreboard a course

Parameter:
	0: String - Name of the course (set via Name attribute)

Returns:
	Nothing

*/

_lnbEntries = (createDialog ["shiny_CQBScoreboard", false]) displayCtrl 1500;

_courseIdentifier = _this call shiny_fnc_getCourseIdentifier;
_scoreList = profilenamespace getVariable[_courseIdentifier, []];

for "_i" from 1 to count _scoreList do {
	_item = _scoreList select (_i - 1); 
	// #0 is playerID
	_unitName = _item select 1;
	_totalTime = _item select 2;

	_timeFormat = _totalTime call shiny_fnc_formatTime;
	_lnbEntries lnbAddRow [str _i, _unitName, _timeFormat];
};