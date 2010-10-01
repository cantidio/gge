dofile("tests/char/mature/mature.lua")
dofile("tests/char/mammon/mammon.lua")
dofile("tests/background/breakman/breakman_layer.lua")

function TestGame()
	local this				= {}	
	this					= GGE_Game()
	this.mWindow.title		= "TEST - GGE"
	this.mVideo.width		= 640
	this.mVideo.height		= 480
	this.mVideo.FPS			= 60
	this.init()


	this.layer = breakman_layer()
	this.layer.addObject(Mature(nil))
	
	this.state = function()
		this.layer.draw({x=150,y=150})
		this.layer.logic()
	end
	
	return this
end
this = TestGame()

