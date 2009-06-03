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

function stateBorning()
	io.write("state borning...\n")
	setMirroring(Mirroring.HFlip)
	state = stateStandInit
end

function stateStandInit()
	io.write("state stand initing...\n")
	changeAnimation(0)
	state = stateStanding
end

function stateStanding()
	if button1() then
		state = stateKick1Init
	elseif button2() then
		state = stateKick2Init
	end
end

function stateKick1Init()
	io.write("state kick1 initing...\n")
	changeAnimation(1)
	state = stateKicking1
end

function stateKicking1()
	if not animationIsPlaying() then
		state = stateStandInit
	end
end

function stateKick2Init()
	io.write("state kick2 initing...\n")
	changeAnimation(2)
	state = stateKicking2
end

function stateKicking2()
	if not animationIsPlaying() then
		state = stateStandInit
	end
end

state = stateBorning
function logic()
	state()
end

