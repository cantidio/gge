function Breakman()
	local this = Background()
	this.gravity		= 0.5
	this.voidFriction	= 1
	this.width			= 256
	this.height			= 224
	this.posX			= 0
	this.posY			= 0
	this.layers			= {
		"data/background/breakman/breakman_layer.lua"
	}
	this.colision		= {
		"",
		""
	}
	this.logic = function ()
--[[		this.getLayer(1).getTile(70).setPosition({x=300,y=66})
		this.getLayer(1).getBackground().getLayer(1).getTile(1).getLayer().getTile(70).setPosition({x=300,y=66})

		this.getLayer(1).getTile(70).setAnimation(12)
		print(this.getLayer(1).getTile(70).getPosition().x)
		print("animation: " .. this.getLayer(1).getTile(70).getAnimation())
-]]
	end
	return this
end
this = Breakman()

