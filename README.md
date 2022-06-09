<p align="center">
  <img style="height: 250px; width: auto;" src="https://user-images.githubusercontent.com/48969167/172837211-72596e36-67ac-47fc-99c3-82d511bb71bc.png" />
</p>

## What is this?

An addon that allows mission makers to build their own CQB courses and measure the time. What you do with it in the end is up to you.

## How to use it?

There are some steps that are necessary for a course to be set up correctly.

You can find a demo mission here: [Demo Mission](https://github.com/EduardSchwarzkopf/shiny_CQB_Demo.VR)

### Step 1 - Control Panel

The control panel can be any object, for example a laptop or a billboard. Give the object a variable name, this name also serves as a course name, e.g. **Your_Course_Name**.

You can also add an addAction directly to the object to show the ranking: `this addAction ["Show Scoreboard", {(_this select 0) spawn shiny_fnc_showScoreboard}];`

### Step 2 - Starter Target

Place a target that must be shot to start the course. Put the following in the init `[this, <Your_Course_Name>] spawn shiny_fnc_courseStart;`
The unit closest to the target is taken as the runner.

### Step 3 - Set Targets

At least one target must be placed for a course. This target must then be registered for the course. This follows with the following command in the init box of the target: `[this, <Your_Course_Name>, 0] spawn shiny_fnc_registerTarget;`

Paremeters are as follows:

0. the target itself
1. course name
2. seconds

With the third paremeter you can define if bonus seconds are given for a target or penalty seconds. For bonus time use minus numbers e.g. -1 for one second or 1 for one penalty second.

```
0 = Target must be hit
> 0 = penalty seconds
< 0 = bonus seconds
```

A course is considered finished when all targets are hit that have a 0 in the 3rd parameter.


