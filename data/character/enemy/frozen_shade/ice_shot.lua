--Arquivo de script do inimigo FrozenShade do jogo castlevania

name				= "Frozen Shade Ice Shot"
sprite				= "data/character/enemy/frozen_shade/frozen.gspk"
animation			= "data/character/enemy/frozen_shade/frozen.gapk"
colision			= "data/character/enemy/frozen_shade/frozen.gcpk"
palette				= ""
xPulse				= 1 
xPulseMax			= 2
yPulse				= 0
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
	if (getXPosition() >= 320 and xPulse > 0) or (getXPosition() <= 0 and xPulse < 0) then
		xPulse = -1 * xPulse/2
	end
	if (getYPosition() >= 240 and yPulse > 0) or (getYPosition() <= 0 and yPulse < 0) then
		yPulse = -1 * yPulse/2
	end
	if xPulse <= 0.5 and xPulse >= -0.5 then
		inativate()
	end
	if yPulse <= 0.5 and yPulse >= -0.5 then
		inativate()
	end
end

initState	= stateInit
state		= initState
function logic()
	state()
end
 
