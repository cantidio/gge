--Background Script File just modify if you know what you are doing
gravity			= 0.5
--Friction of the background in void
voidFriction	= 1
--width of the background
width			= 768
--height of the background
height			= 240
--init x position
posX			= 0
--init y position
posY			= 0
--vector with the layers of the background
--layers			= {
--	"teste_layer0.lua",
--	"teste_layer1.lua",
--}
colision		= {
	"",
	""
}

function state0()
	addXPosition(10)
	if getXPosition() >= 320 then
		state = state1
	end
end

function state1()
	subXPosition(10)
	if getXPosition() <= -320 then
		state = state0
	end
end

state			= state0
function logic()
	state()
end

