--Arquivo de script do inimigo caterpie do jogo rabbitz

name			= "Verme inútil"
sprite			= "data/character/enemy/caterpie.gspk"
animation		= "data/character/enemy/caterpie.gapk"
colision		= "data/character/enemy/caterpie.gcpk"
palette			= ""
xPulse			= 0.3 
xPulseMax		= 2

function logic()

	if isAtive()==true then
		if getMirroring()==0 then
			if  getFrameOn()==1 then
				addPosition(xPulse,0)
			end
		else
			if  getFrameOn()==1 then
				addPosition(-xPulse,0)
			end

		end
	
		if getXPosition()>=330 then
			inativate()
		elseif getXPosition()<=0 then
			inativate()
		end
		
	end
end

