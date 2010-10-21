include("lab1_layer.lua")
include("lab2_layer.lua")

Lab = class()
function Lab:new()
	local self = GGE_Background:new()
	self.width			= 240
	self.height			= 160
	self.posX			= 0
	self.posY			= 0

	self:addLayer( lab2_layer:new(self) )
	self:addLayer( lab1_layer:new(self) )
	
	function self:logic()
		self:basicLogic()
	end
	return self
end

