lab1_layer = class()
function lab1_layer:new(pBackground)
	local self = GGE_Layer:new(
		lab1_layer.__dir .. "lab1_layer.gspk",
		lab1_layer.__dir .. "lab1_layer.gapk",
		pBackground
	)
	self:loadTiles(
		{
			{
				animation	= 0,
				position	= { x = 224, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 208, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 192, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 176, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 160, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 144, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 128, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 112, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 96, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 80, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 64, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 48, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 32, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 16, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 224, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 208, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 192, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 176, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 160, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 144, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 128, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 112, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 96, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 80, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 64, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 48, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 32, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 16, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 128 }
			},
		}
	)
	return self
end

