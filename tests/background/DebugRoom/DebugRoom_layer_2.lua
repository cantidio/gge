DebugRoom_layer_2 = class()
function DebugRoom_layer_2:new(pBackground)
	local self = GGE_Layer:new(
		DebugRoom_layer_2.__dir .. "DebugRoom_layer_2.gspk",
		DebugRoom_layer_2.__dir .. "DebugRoom_layer_2.gapk",
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
				position	= { x = 624, y = 0 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 16 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 16 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 32 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 32 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 48 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 48 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 64 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 64 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 80 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 80 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 96 }
			},
			{
				animation	= 2,
				position	= { x = 608, y = 96 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 96 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 112 }
			},
			{
				animation	= 3,
				position	= { x = 608, y = 112 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 112 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 128 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 128 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 144 }
			},
			{
				animation	= 4,
				position	= { x = 608, y = 144 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 144 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 160 }
			},
			{
				animation	= 5,
				position	= { x = 304, y = 160 }
			},
			{
				animation	= 6,
				position	= { x = 320, y = 160 }
			},
			{
				animation	= 6,
				position	= { x = 336, y = 160 }
			},
			{
				animation	= 6,
				position	= { x = 352, y = 160 }
			},
			{
				animation	= 6,
				position	= { x = 368, y = 160 }
			},
			{
				animation	= 7,
				position	= { x = 384, y = 160 }
			},
			{
				animation	= 4,
				position	= { x = 576, y = 160 }
			},
			{
				animation	= 4,
				position	= { x = 592, y = 160 }
			},
			{
				animation	= 8,
				position	= { x = 608, y = 160 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 160 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 176 }
			},
			{
				animation	= 9,
				position	= { x = 128, y = 176 }
			},
			{
				animation	= 6,
				position	= { x = 144, y = 176 }
			},
			{
				animation	= 10,
				position	= { x = 160, y = 176 }
			},
			{
				animation	= 5,
				position	= { x = 288, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 304, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 320, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 336, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 352, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 368, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 384, y = 176 }
			},
			{
				animation	= 7,
				position	= { x = 400, y = 176 }
			},
			{
				animation	= 12,
				position	= { x = 576, y = 176 }
			},
			{
				animation	= 12,
				position	= { x = 592, y = 176 }
			},
			{
				animation	= 12,
				position	= { x = 608, y = 176 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 176 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 192 }
			},
			{
				animation	= 1,
				position	= { x = 128, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 144, y = 192 }
			},
			{
				animation	= 0,
				position	= { x = 160, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 272, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 288, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 304, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 320, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 336, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 352, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 368, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 384, y = 192 }
			},
			{
				animation	= 11,
				position	= { x = 400, y = 192 }
			},
			{
				animation	= 7,
				position	= { x = 416, y = 192 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 192 }
			},
			{
				animation	= 0,
				position	= { x = 0, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 128, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 144, y = 208 }
			},
			{
				animation	= 0,
				position	= { x = 160, y = 208 }
			},
			{
				animation	= 5,
				position	= { x = 256, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 272, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 288, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 304, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 320, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 336, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 352, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 368, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 384, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 400, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 416, y = 208 }
			},
			{
				animation	= 7,
				position	= { x = 432, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 624, y = 208 }
			},
			{
				animation	= 11,
				position	= { x = 0, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 16, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 32, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 48, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 64, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 80, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 96, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 112, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 128, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 144, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 160, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 176, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 192, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 208, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 224, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 240, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 256, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 272, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 288, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 304, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 320, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 336, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 352, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 368, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 384, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 400, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 416, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 432, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 448, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 464, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 480, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 496, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 512, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 528, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 544, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 560, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 576, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 592, y = 224 }
			},
			{
				animation	= 6,
				position	= { x = 608, y = 224 }
			},
			{
				animation	= 11,
				position	= { x = 624, y = 224 }
			},
		}
	)--end load tiles

	function self:logic()
		self:basicLogic()
		--put your layer logic here
	end

	return self
end

