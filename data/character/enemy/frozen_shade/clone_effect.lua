--Arquivo de script do inimigo FrozenShade do jogo castlevania
-- criar jeito do helper se comunicar com seu "pai"
name				= "Frozen Shade Clone Effect"
sprite				= "data/character/enemy/frozen_shade/frozen.gspk"
animation			= "data/character/enemy/frozen_shade/frozen.gapk"
colision			= "data/character/enemy/frozen_shade/frozen.gcpk"
palette				= ""
xPulse				= 1 
xPulseMax			= 2
helperMaxInstances	= { }
helperScriptFile	= { }

function stateInit()
	changeAnimation(200,0)
	state = stateStand
end

function stateStand()
	if not animationIsPlaying() then
		inativate()
	end
end
initState	= stateInit
state		= initState
function logic()
	state()
end
 
