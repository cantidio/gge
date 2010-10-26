include("DebugRoom_layer_1.lua")
include("DebugRoom_layer_2.lua")

DebugRoom = class()
function DebugRoom:new()
	local self	= GGE_Background:new()
	self.mWidth	= 640
	self.mHeight= 240
	self:addLayer(DebugRoom_layer_1:new(self))
	self:addLayer(DebugRoom_layer_2:new(self))

	function self:logic()
		self:basicLogic()
		--put your background logic here
	end

	return self
end

