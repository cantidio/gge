BreakmanLayer = class()
function BreakmanLayer:new(pBackground)
	GGE_game_log("BreakmanLayer")
	local self	= GGE_Layer:new(
		BreakmanLayer.__dir .. "breakman_layer.gspk",
		BreakmanLayer.__dir .. "breakman_layer.gapk",
		pBackground
	)
	self:loadTiles(
		{
			{
				animation	= 0,
				position	= { x = 240, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 224, y = 208 }
			},
			{
				animation	= 0,
				position	= { x = 208, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 192, y = 208 }
			},
			{
				animation	= 2,
				position	= { x = 176, y = 208 }
			},
			{
				animation	= 3,
				position	= { x = 160, y = 208 }
			},
			{
				animation	= 0,
				position	= { x = 144, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 128, y = 208 }
			},
			{
				animation	= 0,
				position	= { x = 112, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 96, y = 208 }
			},
			{
				animation	= 2,
				position	= { x = 80, y = 208 }
			},
			{
				animation	= 3,
				position	= { x = 64, y = 208 }
			},
			{
				animation	= 0,
				position	= { x = 48, y = 208 }
			},
			{
				animation	= 1,
				position	= { x = 32, y = 208 }
			},
			{
				animation	= 2,
				position	= { x = 16, y = 208 }
			},
			{
				animation	= 3,
				position	= { x = 0, y = 208 }
			},
			{
				animation	= 4,
				position	= { x = 240, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 224, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 208, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 192, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 176, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 160, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 144, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 128, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 112, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 96, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 80, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 64, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 48, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 32, y = 192 }
			},
			{
				animation	= 4,
				position	= { x = 16, y = 192 }
			},
			{
				animation	= 5,
				position	= { x = 0, y = 192 }
			},
			{
				animation	= 6,
				position	= { x = 240, y = 176 }
			},
			{
				animation	= 7,
				position	= { x = 224, y = 176 }
			},
			{
				animation	= 8,
				position	= { x = 208, y = 176 }
			},
			{
				animation	= 7,
				position	= { x = 192, y = 176 }
			},
			{
				animation	= 9,
				position	= { x = 176, y = 176 }
			},
			{
				animation	= 1,
				position	= { x = 160, y = 176 }
			},
			{
				animation	= 2,
				position	= { x = 144, y = 176 }
			},
			{
				animation	= 3,
				position	= { x = 128, y = 176 }
			},
			{
				animation	= 0,
				position	= { x = 112, y = 176 }
			},
			{
				animation	= 1,
				position	= { x = 96, y = 176 }
			},
			{
				animation	= 0,
				position	= { x = 80, y = 176 }
			},
			{
				animation	= 10,
				position	= { x = 64, y = 176 }
			},
			{
				animation	= 8,
				position	= { x = 48, y = 176 }
			},
			{
				animation	= 7,
				position	= { x = 32, y = 176 }
			},
			{
				animation	= 8,
				position	= { x = 16, y = 176 }
			},
			{
				animation	= 11,
				position	= { x = 0, y = 176 }
			},
			{
				animation	= 12,
				position	= { x = 240, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 224, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 208, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 192, y = 160 }
			},
			{
				animation	= 14,
				position	= { x = 176, y = 160 }
			},
			{
				animation	= 5,
				position	= { x = 160, y = 160 }
			},
			{
				animation	= 4,
				position	= { x = 144, y = 160 }
			},
			{
				animation	= 5,
				position	= { x = 128, y = 160 }
			},
			{
				animation	= 4,
				position	= { x = 112, y = 160 }
			},
			{
				animation	= 5,
				position	= { x = 96, y = 160 }
			},
			{
				animation	= 4,
				position	= { x = 80, y = 160 }
			},
			{
				animation	= 15,
				position	= { x = 64, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 48, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 32, y = 160 }
			},
			{
				animation	= 13,
				position	= { x = 16, y = 160 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 160 }
			},
			{
				animation	= 12,
				position	= { x = 240, y = 144 }
			},
			{
				animation	= 13,
				position	= { x = 224, y = 144 }
			},
			{
				animation	= 17,
				position	= { x = 208, y = 144 }
			},
			{
				animation	= 13,
				position	= { x = 192, y = 144 }
			},
			{
				animation	= 18,
				position	= { x = 176, y = 144 }
			},
			{
				animation	= 7,
				position	= { x = 160, y = 144 }
			},
			{
				animation	= 8,
				position	= { x = 144, y = 144 }
			},
			{
				animation	= 7,
				position	= { x = 128, y = 144 }
			},
			{
				animation	= 8,
				position	= { x = 112, y = 144 }
			},
			{
				animation	= 7,
				position	= { x = 96, y = 144 }
			},
			{
				animation	= 19,
				position	= { x = 80, y = 144 }
			},
			{
				animation	= 20,
				position	= { x = 64, y = 144 }
			},
			{
				animation	= 13,
				position	= { x = 48, y = 144 }
			},
			{
				animation	= 13,
				position	= { x = 32, y = 144 }
			},
			{
				animation	= 17,
				position	= { x = 16, y = 144 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 144 }
			},
			{
				animation	= 12,
				position	= { x = 240, y = 128 }
			},
			{
				animation	= 21,
				position	= { x = 224, y = 128 }
			},
			{
				animation	= 22,
				position	= { x = 208, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 192, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 176, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 160, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 144, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 128, y = 128 }
			},
			{
				animation	= 13,
				position	= { x = 112, y = 128 }
			},
			{
				animation	= 21,
				position	= { x = 96, y = 128 }
			},
			{
				animation	= 23,
				position	= { x = 80, y = 128 }
			},
			{
				animation	= 24,
				position	= { x = 64, y = 128 }
			},
			{
				animation	= 25,
				position	= { x = 48, y = 128 }
			},
			{
				animation	= 26,
				position	= { x = 32, y = 128 }
			},
			{
				animation	= 27,
				position	= { x = 16, y = 128 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 128 }
			},
			{
				animation	= 12,
				position	= { x = 240, y = 112 }
			},
			{
				animation	= 28,
				position	= { x = 224, y = 112 }
			},
			{
				animation	= 29,
				position	= { x = 208, y = 112 }
			},
			{
				animation	= 25,
				position	= { x = 192, y = 112 }
			},
			{
				animation	= 13,
				position	= { x = 176, y = 112 }
			},
			{
				animation	= 13,
				position	= { x = 160, y = 112 }
			},
			{
				animation	= 13,
				position	= { x = 144, y = 112 }
			},
			{
				animation	= 13,
				position	= { x = 128, y = 112 }
			},
			{
				animation	= 30,
				position	= { x = 112, y = 112 }
			},
			{
				animation	= 31,
				position	= { x = 96, y = 112 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 112 }
			},
			{
				animation	= 33,
				position	= { x = 64, y = 112 }
			},
			{
				animation	= 34,
				position	= { x = 48, y = 112 }
			},
			{
				animation	= 35,
				position	= { x = 32, y = 112 }
			},
			{
				animation	= 36,
				position	= { x = 16, y = 112 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 112 }
			},
			{
				animation	= 12,
				position	= { x = 240, y = 96 }
			},
			{
				animation	= 37,
				position	= { x = 224, y = 96 }
			},
			{
				animation	= 33,
				position	= { x = 208, y = 96 }
			},
			{
				animation	= 34,
				position	= { x = 192, y = 96 }
			},
			{
				animation	= 13,
				position	= { x = 176, y = 96 }
			},
			{
				animation	= 13,
				position	= { x = 160, y = 96 }
			},
			{
				animation	= 13,
				position	= { x = 144, y = 96 }
			},
			{
				animation	= 13,
				position	= { x = 128, y = 96 }
			},
			{
				animation	= 38,
				position	= { x = 112, y = 96 }
			},
			{
				animation	= 39,
				position	= { x = 96, y = 96 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 96 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 96 }
			},
			{
				animation	= 40,
				position	= { x = 48, y = 96 }
			},
			{
				animation	= 41,
				position	= { x = 32, y = 96 }
			},
			{
				animation	= 42,
				position	= { x = 16, y = 96 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 96 }
			},
			{
				animation	= 43,
				position	= { x = 240, y = 80 }
			},
			{
				animation	= 44,
				position	= { x = 224, y = 80 }
			},
			{
				animation	= 32,
				position	= { x = 208, y = 80 }
			},
			{
				animation	= 40,
				position	= { x = 192, y = 80 }
			},
			{
				animation	= 45,
				position	= { x = 176, y = 80 }
			},
			{
				animation	= 42,
				position	= { x = 160, y = 80 }
			},
			{
				animation	= 13,
				position	= { x = 144, y = 80 }
			},
			{
				animation	= 46,
				position	= { x = 128, y = 80 }
			},
			{
				animation	= 47,
				position	= { x = 112, y = 80 }
			},
			{
				animation	= 48,
				position	= { x = 96, y = 80 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 80 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 80 }
			},
			{
				animation	= 32,
				position	= { x = 48, y = 80 }
			},
			{
				animation	= 49,
				position	= { x = 32, y = 80 }
			},
			{
				animation	= 50,
				position	= { x = 16, y = 80 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 80 }
			},
			{
				animation	= 51,
				position	= { x = 240, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 224, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 208, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 192, y = 64 }
			},
			{
				animation	= 49,
				position	= { x = 176, y = 64 }
			},
			{
				animation	= 50,
				position	= { x = 160, y = 64 }
			},
			{
				animation	= 52,
				position	= { x = 144, y = 64 }
			},
			{
				animation	= 53,
				position	= { x = 128, y = 64 }
			},
			{
				animation	= 54,
				position	= { x = 112, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 96, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 64 }
			},
			{
				animation	= 32,
				position	= { x = 48, y = 64 }
			},
			{
				animation	= 55,
				position	= { x = 32, y = 64 }
			},
			{
				animation	= 56,
				position	= { x = 16, y = 64 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 64 }
			},
			{
				animation	= 51,
				position	= { x = 240, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 224, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 208, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 192, y = 48 }
			},
			{
				animation	= 55,
				position	= { x = 176, y = 48 }
			},
			{
				animation	= 56,
				position	= { x = 160, y = 48 }
			},
			{
				animation	= 57,
				position	= { x = 144, y = 48 }
			},
			{
				animation	= 58,
				position	= { x = 128, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 112, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 96, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 48, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 32, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 16, y = 48 }
			},
			{
				animation	= 59,
				position	= { x = 0, y = 48 }
			},
			{
				animation	= 51,
				position	= { x = 240, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 224, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 208, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 192, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 176, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 160, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 144, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 128, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 112, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 96, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 80, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 48, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 32, y = 32 }
			},
			{
				animation	= 32,
				position	= { x = 16, y = 32 }
			},
			{
				animation	= 60,
				position	= { x = 0, y = 32 }
			},
			{
				animation	= 51,
				position	= { x = 240, y = 16 }
			},
			{
				animation	= 61,
				position	= { x = 224, y = 16 }
			},
			{
				animation	= 62,
				position	= { x = 208, y = 16 }
			},
			{
				animation	= 32,
				position	= { x = 192, y = 16 }
			},
			{
				animation	= 63,
				position	= { x = 176, y = 16 }
			},
			{
				animation	= 64,
				position	= { x = 160, y = 16 }
			},
			{
				animation	= 65,
				position	= { x = 144, y = 16 }
			},
			{
				animation	= 66,
				position	= { x = 128, y = 16 }
			},
			{
				animation	= 67,
				position	= { x = 112, y = 16 }
			},
			{
				animation	= 61,
				position	= { x = 96, y = 16 }
			},
			{
				animation	= 62,
				position	= { x = 80, y = 16 }
			},
			{
				animation	= 32,
				position	= { x = 64, y = 16 }
			},
			{
				animation	= 63,
				position	= { x = 48, y = 16 }
			},
			{
				animation	= 64,
				position	= { x = 32, y = 16 }
			},
			{
				animation	= 65,
				position	= { x = 16, y = 16 }
			},
			{
				animation	= 60,
				position	= { x = 0, y = 16 }
			},
			{
				animation	= 51,
				position	= { x = 240, y = 0 }
			},
			{
				animation	= 68,
				position	= { x = 224, y = 0 }
			},
			{
				animation	= 69,
				position	= { x = 208, y = 0 }
			},
			{
				animation	= 70,
				position	= { x = 192, y = 0 }
			},
			{
				animation	= 71,
				position	= { x = 176, y = 0 }
			},
			{
				animation	= 72,
				position	= { x = 160, y = 0 }
			},
			{
				animation	= 73,
				position	= { x = 144, y = 0 }
			},
			{
				animation	= 74,
				position	= { x = 128, y = 0 }
			},
			{
				animation	= 75,
				position	= { x = 112, y = 0 }
			},
			{
				animation	= 68,
				position	= { x = 96, y = 0 }
			},
			{
				animation	= 69,
				position	= { x = 80, y = 0 }
			},
			{
				animation	= 70,
				position	= { x = 64, y = 0 }
			},
			{
				animation	= 71,
				position	= { x = 48, y = 0 }
			},
			{
				animation	= 72,
				position	= { x = 32, y = 0 }
			},
			{
				animation	= 73,
				position	= { x = 16, y = 0 }
			},
			{
				animation	= 60,
				position	= { x = 0, y = 0 }
			},
		}
	)--end load tiles
	return self
end

