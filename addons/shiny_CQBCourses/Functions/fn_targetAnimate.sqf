_target = param [0,objNull,[objNull]];
_animPhase = param [1,0,[0]];
switch (true) do {
	case (_target isKindOf "shiny_CQBStartingTarget"): {
		{
			_target animate [_x,_animPhase];
		} forEach ["Bottom_Rotate","Target_Bottom_Rotate"];
	 };
	case (_target isKindOf "TargetP_Inf_F"): {
			_target animate ["Terc",_animPhase];
	};
};