include("muro_layer.lua")

Muro = class()
function Muro:new()
	local self = GGE_Background:new()
	self.width			= 1080
	self.height			= 720
	self:addLayer(MuroLayer:new(self))
	
	return self
end

