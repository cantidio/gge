lab2_layer = class()
function lab2_layer:new(pBackground)
	local self = GGE_Layer:new(
		lab2_layer.__dir .. "lab2_layer.gspk",
		lab2_layer.__dir .. "lab2_layer.gapk",
		pBackground
	)	
	self:loadTiles(
		{
			{
				animation	= 0,
				position	= { x = 224, y = 112 }
			},
			{
				animation	= 1,
				position	= { x = 208, y = 112 }
			},
			{
				animation	= 2,
				position	= { x = 192, y = 112 }
			},
			{
				animation	= 3,
				position	= { x = 176, y = 112 }
			},
			{
				animation	= 4,
				position	= { x = 160, y = 112 }
			},
			{
				animation	= 5,
				position	= { x = 144, y = 112 }
			},
			{
				animation	= 6,
				position	= { x = 128, y = 112 }
			},
			{
				animation	= 7,
				position	= { x = 112, y = 112 }
			},
			{
				animation	= 8,
				position	= { x = 96, y = 112 }
			},
			{
				animation	= 9,
				position	= { x = 80, y = 112 }
			},
			{
				animation	= 10,
				position	= { x = 64, y = 112 }
			},
			{
				animation	= 11,
				position	= { x = 48, y = 112 }
			},
			{
				animation	= 12,
				position	= { x = 32, y = 112 }
			},
			{
				animation	= 13,
				position	= { x = 16, y = 112 }
			},
			{
				animation	= 14,
				position	= { x = 0, y = 112 }
			},
			{
				animation	= 15,
				position	= { x = 224, y = 96 }
			},
			{
				animation	= 16,
				position	= { x = 208, y = 96 }
			},
			{
				animation	= 17,
				position	= { x = 192, y = 96 }
			},
			{
				animation	= 18,
				position	= { x = 176, y = 96 }
			},
			{
				animation	= 19,
				position	= { x = 160, y = 96 }
			},
			{
				animation	= 20,
				position	= { x = 144, y = 96 }
			},
			{
				animation	= 21,
				position	= { x = 128, y = 96 }
			},
			{
				animation	= 22,
				position	= { x = 112, y = 96 }
			},
			{
				animation	= 23,
				position	= { x = 96, y = 96 }
			},
			{
				animation	= 24,
				position	= { x = 80, y = 96 }
			},
			{
				animation	= 25,
				position	= { x = 64, y = 96 }
			},
			{
				animation	= 26,
				position	= { x = 48, y = 96 }
			},
			{
				animation	= 27,
				position	= { x = 32, y = 96 }
			},
			{
				animation	= 28,
				position	= { x = 16, y = 96 }
			},
			{
				animation	= 29,
				position	= { x = 0, y = 96 }
			},
			{
				animation	= 30,
				position	= { x = 224, y = 80 }
			},
			{
				animation	= 31,
				position	= { x = 208, y = 80 }
			},
			{
				animation	= 32,
				position	= { x = 192, y = 80 }
			},
			{
				animation	= 33,
				position	= { x = 176, y = 80 }
			},
			{
				animation	= 34,
				position	= { x = 160, y = 80 }
			},
			{
				animation	= 35,
				position	= { x = 144, y = 80 }
			},
			{
				animation	= 36,
				position	= { x = 128, y = 80 }
			},
			{
				animation	= 37,
				position	= { x = 112, y = 80 }
			},
			{
				animation	= 38,
				position	= { x = 96, y = 80 }
			},
			{
				animation	= 39,
				position	= { x = 80, y = 80 }
			},
			{
				animation	= 40,
				position	= { x = 64, y = 80 }
			},
			{
				animation	= 41,
				position	= { x = 48, y = 80 }
			},
			{
				animation	= 42,
				position	= { x = 32, y = 80 }
			},
			{
				animation	= 43,
				position	= { x = 16, y = 80 }
			},
			{
				animation	= 44,
				position	= { x = 0, y = 80 }
			},
			{
				animation	= 45,
				position	= { x = 224, y = 64 }
			},
			{
				animation	= 46,
				position	= { x = 208, y = 64 }
			},
			{
				animation	= 47,
				position	= { x = 192, y = 64 }
			},
			{
				animation	= 48,
				position	= { x = 176, y = 64 }
			},
			{
				animation	= 49,
				position	= { x = 160, y = 64 }
			},
			{
				animation	= 50,
				position	= { x = 144, y = 64 }
			},
			{
				animation	= 51,
				position	= { x = 128, y = 64 }
			},
			{
				animation	= 52,
				position	= { x = 112, y = 64 }
			},
			{
				animation	= 53,
				position	= { x = 96, y = 64 }
			},
			{
				animation	= 54,
				position	= { x = 80, y = 64 }
			},
			{
				animation	= 46,
				position	= { x = 64, y = 64 }
			},
			{
				animation	= 55,
				position	= { x = 48, y = 64 }
			},
			{
				animation	= 56,
				position	= { x = 32, y = 64 }
			},
			{
				animation	= 57,
				position	= { x = 16, y = 64 }
			},
			{
				animation	= 58,
				position	= { x = 0, y = 64 }
			},
			{
				animation	= 59,
				position	= { x = 224, y = 48 }
			},
			{
				animation	= 60,
				position	= { x = 208, y = 48 }
			},
			{
				animation	= 61,
				position	= { x = 192, y = 48 }
			},
			{
				animation	= 62,
				position	= { x = 176, y = 48 }
			},
			{
				animation	= 63,
				position	= { x = 160, y = 48 }
			},
			{
				animation	= 64,
				position	= { x = 144, y = 48 }
			},
			{
				animation	= 65,
				position	= { x = 128, y = 48 }
			},
			{
				animation	= 66,
				position	= { x = 112, y = 48 }
			},
			{
				animation	= 67,
				position	= { x = 96, y = 48 }
			},
			{
				animation	= 68,
				position	= { x = 80, y = 48 }
			},
			{
				animation	= 69,
				position	= { x = 64, y = 48 }
			},
			{
				animation	= 70,
				position	= { x = 48, y = 48 }
			},
			{
				animation	= 71,
				position	= { x = 32, y = 48 }
			},
			{
				animation	= 72,
				position	= { x = 16, y = 48 }
			},
			{
				animation	= 73,
				position	= { x = 0, y = 48 }
			},
			{
				animation	= 74,
				position	= { x = 224, y = 32 }
			},
			{
				animation	= 75,
				position	= { x = 208, y = 32 }
			},
			{
				animation	= 76,
				position	= { x = 192, y = 32 }
			},
			{
				animation	= 77,
				position	= { x = 176, y = 32 }
			},
			{
				animation	= 78,
				position	= { x = 160, y = 32 }
			},
			{
				animation	= 79,
				position	= { x = 144, y = 32 }
			},
			{
				animation	= 46,
				position	= { x = 128, y = 32 }
			},
			{
				animation	= 46,
				position	= { x = 112, y = 32 }
			},
			{
				animation	= 80,
				position	= { x = 96, y = 32 }
			},
			{
				animation	= 46,
				position	= { x = 80, y = 32 }
			},
			{
				animation	= 81,
				position	= { x = 64, y = 32 }
			},
			{
				animation	= 82,
				position	= { x = 48, y = 32 }
			},
			{
				animation	= 83,
				position	= { x = 32, y = 32 }
			},
			{
				animation	= 84,
				position	= { x = 16, y = 32 }
			},
			{
				animation	= 85,
				position	= { x = 0, y = 32 }
			},
			{
				animation	= 86,
				position	= { x = 224, y = 16 }
			},
			{
				animation	= 46,
				position	= { x = 208, y = 16 }
			},
			{
				animation	= 87,
				position	= { x = 192, y = 16 }
			},
			{
				animation	= 88,
				position	= { x = 176, y = 16 }
			},
			{
				animation	= 89,
				position	= { x = 160, y = 16 }
			},
			{
				animation	= 90,
				position	= { x = 144, y = 16 }
			},
			{
				animation	= 91,
				position	= { x = 128, y = 16 }
			},
			{
				animation	= 92,
				position	= { x = 112, y = 16 }
			},
			{
				animation	= 93,
				position	= { x = 96, y = 16 }
			},
			{
				animation	= 94,
				position	= { x = 80, y = 16 }
			},
			{
				animation	= 95,
				position	= { x = 64, y = 16 }
			},
			{
				animation	= 96,
				position	= { x = 48, y = 16 }
			},
			{
				animation	= 97,
				position	= { x = 32, y = 16 }
			},
			{
				animation	= 98,
				position	= { x = 16, y = 16 }
			},
			{
				animation	= 99,
				position	= { x = 0, y = 16 }
			},
			{
				animation	= 100,
				position	= { x = 224, y = 0 }
			},
			{
				animation	= 101,
				position	= { x = 208, y = 0 }
			},
			{
				animation	= 102,
				position	= { x = 192, y = 0 }
			},
			{
				animation	= 103,
				position	= { x = 176, y = 0 }
			},
			{
				animation	= 104,
				position	= { x = 160, y = 0 }
			},
			{
				animation	= 105,
				position	= { x = 144, y = 0 }
			},
			{
				animation	= 106,
				position	= { x = 128, y = 0 }
			},
			{
				animation	= 107,
				position	= { x = 112, y = 0 }
			},
			{
				animation	= 108,
				position	= { x = 96, y = 0 }
			},
			{
				animation	= 109,
				position	= { x = 80, y = 0 }
			},
			{
				animation	= 110,
				position	= { x = 64, y = 0 }
			},
			{
				animation	= 111,
				position	= { x = 48, y = 0 }
			},
			{
				animation	= 112,
				position	= { x = 32, y = 0 }
			},
			{
				animation	= 113,
				position	= { x = 16, y = 0 }
			},
			{
				animation	= 114,
				position	= { x = 0, y = 0 }
			},
		}
	)
	return self
end

