--Arquivo de script do inimigo caterpie do jogo rabbitz

name				= "Pong"
sprite				= "data/character/player/pong.gspk"
animation			= "data/character/player/pong.gapk"
palette				= ""
yPulse				= 2
xPulse				= 2
xPulseMax			= 2
life				= 10
imortalTime			= 30


function logic()
	if state==0 then
		changeAnimation(0)
		setPosition(10,30)
		state=1
	else
		if buttonUp() then
			addPosition(0,-2)
		elseif buttonDown() then
			addPosition(0,2)
		end
	end
end
 
