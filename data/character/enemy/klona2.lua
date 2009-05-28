--Arquivo de script do inimigo caterpie do jogo rabbitz

name			= "Klona"
sprite			= "resources/character/enemy/klona.gspk"
animation		= "resources/character/enemy/klona.gapk"
colision		= "resources/character/enemy/klona.gcpk"
palette			= ""
xPulse			= 1 
xPulseMax		= 2

function logic()

	if state==0 then
		changeAnimation(1)
		state=1;
	elseif state==1 then
		addPosition(5,0)
		if getXPosition()>=300 then
			setMirroring(1)
			state=2
		end
	elseif state==2 then
		addPosition(-5,0)
		if getXPosition()<=0 then
			setMirroring(0)
			state=1
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
 
