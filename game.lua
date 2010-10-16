dofile("tests/char/mature/mature.lua")
dofile("tests/char/mammon/mammon.lua")
dofile("tests/background/breakman/breakman_background.lua")
--dofile("tools/saveroom/teste.lua")

function TestGame()
	local this				= {}
	this					= GGE_Game()
	this.mWindow.title		= "TEST - GGE"
	this.mVideo.width		= 320
	this.mVideo.height		= 240
	this.mVideo.FPS			= 60
	this.init()


	this.BG = Breakman()
	this.BG.getLayer(1).addObject(Mature(nil))
	this.BG.getLayer(1).addObject(Mature(nil))
--	this.BG.setPosition({x=30,y=50})
	this.state = function()
		this.BG.draw()
		this.BG.logic()
	end
	
	return this
end
this = TestGame()

