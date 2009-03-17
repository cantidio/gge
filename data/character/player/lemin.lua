--Arquivo de script do inimigo caterpie do jogo rabbitz

name				= "Klona"
sprite				= "data/character/enemy/klona.gspk"
animation			= "data/character/enemy/klona.gapk"
colision			= "data/character/enemy/klona.gcpk"
palette				= ""
xPulse				= 2
xPulseMax			= 2
life				= 10
imortalTime			= 30
helperMaxInstances	= {8}
helperScriptFile	= {"data/character/enemy/caterpie.lua"}

function stateStading()
	if buttonRight() or buttonLeft() then
			changeAnimation(1)
			state=1;
			print("state: walking");
		end
end

function stateWalking()
	if buttonRight() then
		setMirroring(Mirroring.Normal)
		if getFrameOn()>0 and getXPosition()<310 then
			addPosition(xPulse,0)
		end
	elseif buttonLeft() then
		setMirroring(Mirroring.HFlip)
		if getFrameOn()>0 and getXPosition()>10 then
			addPosition(-xPulse,0)
		end
	else
		changeAnimation(0)
		state=0
		print("state: standing");
	end
end

function logic()
	if state==0 then
		stateStading()
	elseif state==1 then
		stateWalking()
	end
end
 
