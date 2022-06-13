/*
Author: Eduard Schwarzkopf

Description:
	Makes sure, that the string is valid as an identifier
	https://community.bistudio.com/wiki/Identifier

Parameter:
	0: String

Returns:
	String

*/

_prefix = "shiny_CQBCourses_Score_";
_name = _this regexReplace ["\W", ""];
_identifier = [_prefix, _name] joinString "";
_identifier;
