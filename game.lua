--chars
include("tests/char/Foxy/foxy.lua")
--include("tests/char/mature/mature.lua")
--include("tests/char/frozen_shade/frozen_shade.lua")
--include("tests/char/mammon/mammon.lua")
--BGS
--include("tools/SaveRoom/Castlevania_Save_Room.lua")
include("tests/background/Rugal/rugal.lua")
--[[include("tests/background/DebugRoom/DebugRoom.lua")
include("tests/background/saveroom/SaveRoom.lua")
include("tests/background/breakman/breakman_background.lua")
include("tests/background/lab/lab.lua")
include("tests/background/muro/muro.lua")
-]]
TestGame = class()	-- Manila Chase Scene
function TestGame:new()
	local self = GGE_Game:new()
	self.mWindow.title		= "TEST - GGE"
	self.mVideo.width		= 640
	self.mVideo.height		= 480
	self.mVideo.FPS			= 60
	self.mVideo.fullScreen		= false--true
	self:init()
--	self.BG		= DebugRoom:new()
	self.BG		= RugalBG:new()
	self.obj	= Foxy:new({x=160,y=220})

	
	
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

An = 1
this.obj.logic = function()
	this.obj:basicLogic()
	this.obj:state()
	if this.obj.mInput:buttonUp() and An > 0 then
		An = An - 1
		this.obj:changeAnimationByIndex(An)
	elseif this.obj.mInput:buttonDown() and An < 257 then
		An = An + 1
		this.obj:changeAnimationByIndex(An)
    end
end

a = this.BG:getLayer(2):addObject( Foxy:new({x=260,y=220}) )
a:changeAnimation(195,0)
a.logic = function()
	a:basicLogic()
	if a:getPosition().x > this.obj:getPosition().x then
		a:setMirroring( Mirroring.HFlip)
	else
		a:setMirroring( Mirroring.Normal)
	end
end
	
