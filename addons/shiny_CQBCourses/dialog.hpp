class shiny_CQBScoreboard
{
	idd = 7000;
	class controlsBackground
	{
		class back: RscText
		{
			colorBackground[] = {0,0,0,0.8};
			x = -16.5 * GUI_GRID_W + 0.5;
			y = -6.5 * GUI_GRID_H + 0.5;
			w = 33 * GUI_GRID_W;
			h = 15.5 * GUI_GRID_H;
		};
		class title: RscStructuredText
		{
			text = "Scoreboard";
			colorBackground[]={0.8,0.5,0,1};
			x = -16.5 * GUI_GRID_W + 0.5;
			y = -7.6 * GUI_GRID_H + 0.5;
			w = 33 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
	};
	class controls
	{
		#define W_LNB (32 * GUI_GRID_W)
		class lnbEntries: RscListNBox
		{
			idc = 1500;
			columns[] = {0, 1/12, 8/12};
			x = -16 * GUI_GRID_W + 0.5;
			y = -5 * GUI_GRID_H + 0.5;
			w = W_LNB;
			h = 12 * GUI_GRID_H;
		};
		class grpSortBtns: RscControlsGroup
		{
			idc = 2300;
			x = -16 * GUI_GRID_W + 0.5;
			y = -6 * GUI_GRID_H + 0.5;
			w = W_LNB;
			h = 1 * GUI_GRID_H;
			class Controls
			{
				class btnSortCol1: RscText
				{
					idc = 2400;
					text = "#";
					style=ST_LEFT;
					colorFocused[]={1,1,1,0.5};
					colorFocused2[]={1,1,1,0.1};
					period=1.2;
					x = 0;
					y = 0;
					w = 1/12 * W_LNB;
					h = GUI_GRID_H;
				};
				class btnSortCol2: btnSortCol1
				{
					idc = 2401;
					text = "Name";
					x = 1/12 * W_LNB;
					w = 8/12 * W_LNB;
				};
				class btnSortCol3: btnSortCol1
				{
					idc = 2402;
					text = "Time";
					x = 8/12 * W_LNB;
					w = 4/12 * W_LNB;
				};
			};
		};
		class btnOK: RscButtonMenuOK
		{
			x = 8 * GUI_GRID_W + 0.5;
			y = 7.5 * GUI_GRID_H + 0.5;
			w = 8 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
	};
};
