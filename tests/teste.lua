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
layers			= {
	"teste_layer0.lua",
	"teste_layer1.lua",
}
colision		= {
	"",
	""
}

function stateRightInit()
	io.write("background state: stateRight\n")
	state = stateRight
end

function stateRight()
	addXPosition(1)
	if getXPosition() >= 320 then
		state = stateLeftInit
	end
end

function stateLeftInit()
	io.write("background state: stateLeft\n")
	state = stateLeft
end

function stateLeft()
	subXPosition(1)
	if getXPosition() <= -320 then
		state = stateRightInit
	end
end

state = stateRightInit
function logic()
	--state()
end

