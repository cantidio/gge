--Arquivo de script do inimigo FrozenShade do jogo castlevania

dofile("data/character/character_class.lua")

name				= "Frozen Shade"
sprite				= "data/character/enemy/frozen_shade/frozen.gspk"
animation			= "data/character/enemy/frozen_shade/frozen.gapk"
colision			= "data/character/enemy/frozen_shade/frozen.gcpk"
palette				= ""
xPulse				= 3
xPulseMax			= 5
helperMaxInstances	= { 1, 50}
helperScriptFile	= {
	"data/character/enemy/frozen_shade/clone_effect.lua",
	"data/character/enemy/frozen_shade/ice_shot.lua",
}
-- Instância do clone do personagem
clone 				= {}

function stateInitShotBegin()
	print("state: InitShot")
	changeAnimation(100,0)
	state = stateInitShot
end

function stateInitShot()
	if not animationIsPlaying() then
		stateShotBegin()
	end
end

function stateShotBegin()
	changeAnimation(1000,2)
	print("state: Shotting")
	clone = Character(
		callHelper(
			getXPosition(),
			getYPosition(),
			getMirroring(),
			0
		)
	)
	subYPosition(25)
	state = stateShot
end

function stateShot()
	if not clone.isAtive() then
		stateStandBegin()
		addYPosition(25)
	elseif getFrameOn() == 0 or getFrameOn() == 2 then
		callHelper(
			getXPosition() + 20,
			getYPosition() - 7,
			getMirroring(),
			1
		)
	end
end

function stateStandBegin()
	print("state: Stand")
	changeAnimation(0,0)
	state = stateStand
end

function stateStand()
	if button1() then
		stateInitShotBegin()
	else
		if buttonRight() then
			addXPosition(xPulse)
		elseif buttonLeft() then
			subXPosition(xPulse)
		end
		if buttonDown() then
			addYPosition(xPulse)
		elseif buttonUp() then
			subYPosition(xPulse)
		end
	end
end

function stateInit()
	print("state: Init")
	setAfterImageMode(true,2,10)
	setAfterImageMethodAdd(0,0,50,0,0,0,0.5)
	--setAfterImageMethodNormal()
	stateStandBegin()
end

initState	= stateStandBegin
state 		= stateInit

function logic()
	
	state()
end
 
