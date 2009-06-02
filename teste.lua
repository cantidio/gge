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
state			= 0

function logic()
	if state==0 then
		addXPosition(1)
		if getXPosition() >=320 then
			state=1
		end
	else
		subXPosition(1)
		if getXPosition() <=-320 then
			state=0
		end
	end
	--Put your background logic here
end

