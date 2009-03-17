--Arquivo de script do inimigo caterpie do jogo rabbitz

name				= "Klona"
sprite				= "resources/character/enemy/klona.gspk"
animation			= "resources/character/enemy/klona.gapk"
colision			= "resources/character/enemy/klona.gcpk"
palette				= ""
xPulse				= 6
xPulseMax			= 2
life				= 10
imortalTime			= 30
helperMaxInstances	= {8}
helperScriptFile	= {"resources/character/enemy/caterpie.lua"}

function logic()
	if state==0 then
		changeAnimation(1)
		state=1;
	elseif state==1 then
		addPosition(xPulse,0)
		if getXPosition()>=300 then
	
			state=2
			setMirroring(Mirroring.HFlip)
			callHelper(getXPosition()-30,getYPosition()-30,getMirroring())
	
		end
	elseif state==2 then
		addPosition(-xPulse,0)
		if getXPosition()<=0 then
	
			state=1
			setMirroring(Mirroring.Normal)
			callHelper(getXPosition()+30,getYPosition()-30,getMirroring())
			
		end
	else
		changeAnimation(2)
		addPosition(1,1)
		if not animationIsPlaying() then
			state=2
		end
		state=1
		--print "morto"
	end
end

