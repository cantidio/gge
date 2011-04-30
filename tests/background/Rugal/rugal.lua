RugalBG_layer0 = class()
function RugalBG_layer0:new(pBackground)
	local self = GGE_Layer:new(
		RugalBG_layer0.__dir .. "rugal.gsp",
		RugalBG_layer0.__dir .. "rugal.gap",
		pBackground
	)
	self.mScrollSpeed.x = 0.11
	self.mScrollSpeed.y = 0.8
	self:loadTiles(
		{
			{
				animation	= 1,
				position	= { x = 180, y = 145}
			},
		}
	)
	return self
end

RugalBG_layer1 = class()
function RugalBG_layer1:new(pBackground)
	local self = GGE_Layer:new(
		RugalBG_layer1.__dir .. "rugal.gsp",
		RugalBG_layer1.__dir .. "rugal.gap",
		pBackground
	)
	self:loadTiles(
		{
--			{
--				animation	= 0,
--				position	= { x = 344, y = 240}
--			},
			{
				animation	= 1,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 2,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 3,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 4,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 5,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 6,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 7,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 8,
				position	= { x = 344, y = 240}
			},
		}
	)
	return self
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
				position	= { x = 344, y = 240}
			},
			{
				animation	= 10,
				position	= { x = 344, y = 240}
			},
			{
				animation	= 11,
				position	= { x = 344, y = 240}
			},
		}
	)
	return self
end

RugalBG = class()
function RugalBG:new()
	local self = GGE_Background:new()
	self.mWidth			= 432
	self.mHeight		= 240
	self.mPosition.x	= 0
	self.mPosition.y	= 0
	self.mInput 		= GGE_Input:new()
	self:addLayer( RugalBG_layer0:new(self) )
	self:addLayer( RugalBG_layer1:new(self) )
	self:addLayer( RugalBG_layer2:new(self) )
	
	function self:logic()
		self:basicLogic()
		if self.mInput:buttonRight() then
			self:addPosition({x=2, y=0})
		elseif self.mInput:buttonLeft() then
			self:subPosition({x=2, y=0})
		end
		--self:addPosition({x=1,y=1})
		--print(self:getPosition().x .." " .. self:getPosition().y)
	end
	return self
end



