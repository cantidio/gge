RugalBG_layer1 = class()
function RugalBG_layer1:new(pBackground)
	local self = GGE_Layer:new(
		lab1_layer.__dir .. "rugal.gsp",
		lab1_layer.__dir .. "rugal.gap",
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
	
	function self:logic()
		self:basicLogic()
		--put your layer logic here
	end
end

RugalBG_layer2 = class()
function RugalBG_layer2:new(pBackground)
	local self = GGE_Layer:new(
		lab1_layer.__dir .. "rugal.gsp",
		lab1_layer.__dir .. "rugal.gap",
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
	
	function self:logic()
		self:basicLogic()
		--put your layer logic here
	end
end
