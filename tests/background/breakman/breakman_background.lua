dofile("tests/background/breakman/breakman_layer.lua")

function Breakman()
	GGE_game_log("Breakman")
	local this = GGE_Background()
	
	this.width			= 256
	this.height			= 224
	this.addLayer( BreakmanLayer() )

	this.flag = true
	this.logic = function()
		this.basicLogic()
		local tile = math.random(1,this.getLayer(1).getTileNumber())
		local dir  = math.random(0,70)
		--this.getLayer(1).getTile(tile).addPosition({x=5*dir,y=0})
		this.getLayer(1).getTile(tile).setAnimation(dir)
		--[[if this.flag then
			this.getLayer(1).getBackground().getLayer(1).getTile(70).addPosition({x=5,y=0})
			if this.getLayer(1).getBackground().getLayer(1).getTile(70).getPosition().x > 320 then
				this.flag = false
			end
		else 
			this.getLayer(1).getBackground().getLayer(1).getTile(70).subPosition({x=5,y=0})
			if this.getLayer(1).getBackground().getLayer(1).getTile(70).getPosition().x < 0 then
				this.flag=true
			end
		end-]]
		
--[[		this.getLayer(1).getBackground().getLayer(1).getTile(1).getLayer().getTile(70).setPosition({x=300,y=66})
		this.getLayer(1).getTile(70).setAnimation(12)
		print(this.getLayer(1).getTile(70).getPosition().x)
		print("animation: " .. this.getLayer(1).getTile(70).getAnimation())
-]]
	end
	return this
end

