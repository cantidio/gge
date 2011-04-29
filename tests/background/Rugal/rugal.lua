RugalBG_layer1 = class()
function RugalBG_layer1:new(pBackground)
	local self = GGE_Layer:new(
		RugalBG_layer1.__dir .. "rugal.gsp",
		RugalBG_layer1.__dir .. "rugal.gap",
		pBackground
	)
	self:loadTiles(
		{
			{
				animation	= 0,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 1,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 2,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 3,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 4,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 5,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 6,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 7,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 8,
				position	= { x = 0, y = 0 }
			},
		}
	)
end

RugalBG_layer2 = class()
function RugalBG_layer2:new(pBackground)
	local self = GGE_Layer:new(
		RugalBG_layer2.__dir .. "rugal.gsp",
		RugalBG_layer2.__dir .. "rugal.gap",
		pBackground
	)
	self:loadTiles(
		{
			{
				animation	= 9,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 10,
				position	= { x = 0, y = 0 }
			},
			{
				animation	= 11,
				position	= { x = 0, y = 0 }
			},
		}
	)
end

RugalBG = class()
function RugalBG:new()
	local self = GGE_Background:new()
	self.width			= 432
	self.height			= 240
	self.posX			= 0
	self.posY			= 0

	self:addLayer( RugalBG_layer1:new(self) )
	self:addLayer( RugalBG_layer2:new(self) )
	
	function self:logic()
		self:basicLogic()
	end
	return self
end



