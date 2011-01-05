--chars
include("tests/char/mature/mature.lua")
include("tests/char/frozen_shade/frozen_shade.lua")
include("tests/char/mammon/mammon.lua")
--BGS
include("tests/background/DebugRoom/DebugRoom.lua")
include("tests/background/saveroom/SaveRoom.lua")
include("tests/background/breakman/breakman_background.lua")
include("tests/background/lab/lab.lua")
include("tests/background/muro/muro.lua")

TestGame = class()	-- Manila Chase Scene
function TestGame:new()
	local self = GGE_Game:new()
	self.mWindow.title		= "TEST - GGE"
	self.mVideo.width		= 320
	self.mVideo.height		= 240
	self.mVideo.FPS			= 60
--	self.mVideo.fullScreen	= true
	self:init()
	self.BG		= DebugRoom:new()
	self.obj	= FrozenShade:new({x=80,y=150})
	self.BG:getLayer(2):addObject( self.obj )
	self.BG:setCameraTarget(self.obj)
	
--	local arg = GGE_game_getArgs()
--	for k,v in ipairs( arg ) do
--		print(v)
--	end

	function self:state()
		self.BG:draw()
		self.BG:logic()
	end

	return self
end
this = TestGame:new()

