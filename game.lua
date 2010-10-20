--dofile("tests/char/mature/mature.lua")
dofile("tests/char/frozen_shade/frozen_shade.lua")
dofile("tests/background/saveroom/teste.lua")
--dofile("tests/char/mammon/mammon.lua")

--dofile("tests/background/breakman/breakman_background.lua")

--dofile("tools/saveroom/teste.lua")

TestGame = class(
	function(self)
		self.super:constructor()
		self.mWindow.title		= "TEST - GGE"
		self.mVideo.width		= 640
		self.mVideo.height		= 480
		self.mVideo.FPS			= 120

		self:init()

		self.BG = teste()
		self.BG.getLayer(1).addObject(FrozenShade:new())
	
		self.BG.setPosition({x=30, y=50})
	end,
	GGE_Game
)

function TestGame:state()
	self.BG.draw()
	self.BG.logic()
end
this = TestGame:new()

