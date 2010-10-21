--dofile("tests/char/mature/mature.lua")

include("tests/char/frozen_shade/frozen_shade.lua")
include("tests/background/saveroom/SaveRoom.lua")
include("tests/background/breakman/breakman_background.lua")
include("tests/background/lab/lab.lua")
include("tests/background/muro/muro.lua")

--dofile("tests/char/mammon/mammon.lua")

--dofile("tools/saveroom/teste.lua")
TestGame = class()
function TestGame:new()
	local self = GGE_Game:new()
	self.mWindow.title		= "TEST - GGE"
	self.mVideo.width		= 640
	self.mVideo.height		= 480
	self.mVideo.FPS			= 120

	self:init()
	self.BG = Muro:new()
	self.BG:getLayer(1):addObject( FrozenShade:new() )
	--self.BG:setPosition({x=30, y=50})
	
	function self:state()
		self.BG:draw()
		self.BG:logic()
	end

	return self
end

this = TestGame:new()

