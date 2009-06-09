--Arquivo de script do inimigo FrozenShade do jogo castlevania

name				= "Frozen Shade Ice Shot"
sprite				= "data/character/enemy/frozen_shade/frozen.gspk"
animation			= "data/character/enemy/frozen_shade/frozen.gapk"
colision			= "data/character/enemy/frozen_shade/frozen.gcpk"
palette				= ""
xPulse				= 1 
xPulseMax			= 2
helperMaxInstances	= { }
helperScriptFile	= { }

function stateInit()
	changeAnimation(1000,1)
	xPulse	= math.random(2,5)
	yPulse	= math.random(-2,2)
	state	= stateStand
end

function stateStand()
	addPosition(xPulse,yPulse)
	if getXPosition() >= 320 or getYPosition() >= 240 then
		inativate()
	end
end

initState	= stateInit
state		= initState
function logic()
	state()
end
 
