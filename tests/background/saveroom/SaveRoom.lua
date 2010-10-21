include("SaveRoom_layer_1.lua")
include("SaveRoom_layer_2.lua")

SaveRoom = class()
function SaveRoom:new()
	local self	= GGE_Background:new()
	self.width	= 256
	self.height	= 240
	self:addLayer(SaveRoom_layer_1:new(self))
	self:addLayer(SaveRoom_layer_2:new(self))

	function self:logic()
		self:basicLogic()
		--put your background logic here
	end

	return self
end

