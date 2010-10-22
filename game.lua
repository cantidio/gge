--chars
include("tests/char/mature/mature.lua")
include("tests/char/frozen_shade/frozen_shade.lua")
include("tests/char/mammon/mammon.lua")
--BGS
include("tests/background/saveroom/SaveRoom.lua")
include("tests/background/breakman/breakman_background.lua")
include("tests/background/lab/lab.lua")
include("tests/background/muro/muro.lua")


TestGame = class()
function TestGame:new()
	local self = GGE_Game:new()
	self.mWindow.title		= "TEST - GGE"
	self.mVideo.width		= 640
	self.mVideo.height		= 480
	self.mVideo.FPS			= 120

	self:init()
	self.BG = SaveRoom:new()
	self.BG:getLayer(1):addObject( Mammon:new({x=80,y=150}) )
	--self.BG:setPosition({x=30, y=50})
	
	function self:state()
		self.BG:draw()
		self.BG:logic()
	end

	return self
end

this = TestGame:new()

