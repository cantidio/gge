name				= "Mature"
sprite				= "data/character/player/mature.gspk"
animation			= "data/character/player/mature.gapk"
colision			= "data/character/player/mature.gcpk"
palette				= ""
xPulse				= 3
xPulseMax			= 4
life				= 1000
imortalTime			= 0
helperMaxInstances	= { }
helperScriptFile	= { }

function stateStandInit()
	io.write("state stand initing...\n")
	changeAnimation(0)
	state = stateStanding
end

function stateStanding()
	if button1() then
		changeAnimation(1)
		state = stateKickInit
	end
end

function stateKickInit()
	io.write("state kick initing...\n")
	changeAnimation(1)
	state = stateKicking
end

function stateKicking()
	if not animationIsPlaying() then
		state = stateStandInit
	end
end

state = stateStandInit
function logic()
	state()
end

