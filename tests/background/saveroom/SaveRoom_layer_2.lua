SaveRoom_layer_2 = class()
function SaveRoom_layer_2:new(pBackground)
	local self = GGE_Layer:new(
		SaveRoom_layer_2.__dir .. "SaveRoom_layer_2.gspk",
		SaveRoom_layer_2.__dir .. "SaveRoom_layer_2.gapk",
		pBackground
	)
	self:loadTiles(
		{
			{
				animation	= 0,
				position	= { x = 0, y = 32 }
			},
			{
				animation	= 1,
				position	= { x = 16, y = 32 }
			},
			{
				animation	= 2,
				position	= { x = 32, y = 32 }
			},
			{
				animation	= 3,
				position	= { x = 48, y = 32 }
			},
			{
				animation	= 4,
				position	= { x = 64, y = 32 }
			},
			{
				animation	= 5,
				position	= { x = 80, y = 32 }
			},
			{
				animation	= 6,
				position	= { x = 96, y = 32 }
			},
			{
				animation	= 7,
				position	= { x = 112, y = 32 }
			},
			{
				animation	= 8,
				position	= { x = 128, y = 32 }
			},
			{
				animation	= 9,
				position	= { x = 144, y = 32 }
			},
			{
				animation	= 10,
				position	= { x = 160, y = 32 }
			},
			{
				animation	= 11,
				position	= { x = 176, y = 32 }
			},
			{
				animation	= 12,
				position	= { x = 192, y = 32 }
			},
			{
				animation	= 13,
				position	= { x = 208, y = 32 }
			},
			{
				animation	= 14,
				position	= { x = 224, y = 32 }
			},
			{
				animation	= 15,
				position	= { x = 240, y = 32 }
			},
			{
				animation	= 16,
				position	= { x = 0, y = 48 }
			},
			{
				animation	= 17,
				position	= { x = 16, y = 48 }
			},
			{
				animation	= 18,
				position	= { x = 32, y = 48 }
			},
			{
				animation	= 19,
				position	= { x = 48, y = 48 }
			},
			{
				animation	= 20,
				position	= { x = 64, y = 48 }
			},
			{
				animation	= 21,
				position	= { x = 80, y = 48 }
			},
			{
				animation	= 22,
				position	= { x = 96, y = 48 }
			},
			{
				animation	= 23,
				position	= { x = 112, y = 48 }
			},
			{
				animation	= 24,
				position	= { x = 128, y = 48 }
			},
			{
				animation	= 25,
				position	= { x = 144, y = 48 }
			},
			{
				animation	= 26,
				position	= { x = 160, y = 48 }
			},
			{
				animation	= 27,
				position	= { x = 176, y = 48 }
			},
			{
				animation	= 28,
				position	= { x = 192, y = 48 }
			},
			{
				animation	= 29,
				position	= { x = 208, y = 48 }
			},
			{
				animation	= 30,
				position	= { x = 224, y = 48 }
			},
			{
				animation	= 31,
				position	= { x = 240, y = 48 }
			},
			{
				animation	= 32,
				position	= { x = 0, y = 64 }
			},
			{
				animation	= 33,
				position	= { x = 16, y = 64 }
			},
			{
				animation	= 34,
				position	= { x = 32, y = 64 }
			},
			{
				animation	= 35,
				position	= { x = 48, y = 64 }
			},
			{
				animation	= 36,
				position	= { x = 192, y = 64 }
			},
			{
				animation	= 37,
				position	= { x = 208, y = 64 }
			},
			{
				animation	= 38,
				position	= { x = 224, y = 64 }
			},
			{
				animation	= 39,
				position	= { x = 240, y = 64 }
			},
			{
				animation	= 40,
				position	= { x = 0, y = 80 }
			},
			{
				animation	= 41,
				position	= { x = 16, y = 80 }
			},
			{
				animation	= 42,
				position	= { x = 32, y = 80 }
			},
			{
				animation	= 43,
				position	= { x = 48, y = 80 }
			},
			{
				animation	= 44,
				position	= { x = 192, y = 80 }
			},
			{
				animation	= 45,
				position	= { x = 208, y = 80 }
			},
			{
				animation	= 46,
				position	= { x = 224, y = 80 }
			},
			{
				animation	= 47,
				position	= { x = 240, y = 80 }
			},
			{
				animation	= 48,
				position	= { x = 0, y = 96 }
			},
			{
				animation	= 49,
				position	= { x = 16, y = 96 }
			},
			{
				animation	= 50,
				position	= { x = 32, y = 96 }
			},
			{
				animation	= 51,
				position	= { x = 48, y = 96 }
			},
			{
				animation	= 52,
				position	= { x = 192, y = 96 }
			},
			{
				animation	= 53,
				position	= { x = 208, y = 96 }
			},
			{
				animation	= 54,
				position	= { x = 224, y = 96 }
			},
			{
				animation	= 55,
				position	= { x = 240, y = 96 }
			},
			{
				animation	= 56,
				position	= { x = 0, y = 112 }
			},
			{
				animation	= 57,
				position	= { x = 16, y = 112 }
			},
			{
				animation	= 58,
				position	= { x = 32, y = 112 }
			},
			{
				animation	= 59,
				position	= { x = 208, y = 112 }
			},
			{
				animation	= 60,
				position	= { x = 224, y = 112 }
			},
			{
				animation	= 61,
				position	= { x = 240, y = 112 }
			},
			{
				animation	= 62,
				position	= { x = 0, y = 128 }
			},
			{
				animation	= 63,
				position	= { x = 16, y = 128 }
			},
			{
				animation	= 64,
				position	= { x = 32, y = 128 }
			},
			{
				animation	= 65,
				position	= { x = 208, y = 128 }
			},
			{
				animation	= 66,
				position	= { x = 224, y = 128 }
			},
			{
				animation	= 67,
				position	= { x = 240, y = 128 }
			},
			{
				animation	= 62,
				position	= { x = 0, y = 144 }
			},
			{
				animation	= 68,
				position	= { x = 16, y = 144 }
			},
			{
				animation	= 69,
				position	= { x = 32, y = 144 }
			},
			{
				animation	= 70,
				position	= { x = 208, y = 144 }
			},
			{
				animation	= 71,
				position	= { x = 224, y = 144 }
			},
			{
				animation	= 67,
				position	= { x = 240, y = 144 }
			},
			{
				animation	= 48,
				position	= { x = 0, y = 160 }
			},
			{
				animation	= 49,
				position	= { x = 16, y = 160 }
			},
			{
				animation	= 72,
				position	= { x = 32, y = 160 }
			},
			{
				animation	= 73,
				position	= { x = 208, y = 160 }
			},
			{
				animation	= 54,
				position	= { x = 224, y = 160 }
			},
			{
				animation	= 55,
				position	= { x = 240, y = 160 }
			},
			{
				animation	= 74,
				position	= { x = 0, y = 176 }
			},
			{
				animation	= 75,
				position	= { x = 16, y = 176 }
			},
			{
				animation	= 69,
				position	= { x = 32, y = 176 }
			},
			{
				animation	= 76,
				position	= { x = 80, y = 176 }
			},
			{
				animation	= 77,
				position	= { x = 96, y = 176 }
			},
			{
				animation	= 78,
				position	= { x = 112, y = 176 }
			},
			{
				animation	= 79,
				position	= { x = 128, y = 176 }
			},
			{
				animation	= 80,
				position	= { x = 144, y = 176 }
			},
			{
				animation	= 81,
				position	= { x = 160, y = 176 }
			},
			{
				animation	= 70,
				position	= { x = 208, y = 176 }
			},
			{
				animation	= 82,
				position	= { x = 224, y = 176 }
			},
			{
				animation	= 83,
				position	= { x = 240, y = 176 }
			},
			{
				animation	= 62,
				position	= { x = 0, y = 192 }
			},
			{
				animation	= 84,
				position	= { x = 16, y = 192 }
			},
			{
				animation	= 85,
				position	= { x = 32, y = 192 }
			},
			{
				animation	= 86,
				position	= { x = 80, y = 192 }
			},
			{
				animation	= 87,
				position	= { x = 96, y = 192 }
			},
			{
				animation	= 88,
				position	= { x = 112, y = 192 }
			},
			{
				animation	= 89,
				position	= { x = 128, y = 192 }
			},
			{
				animation	= 90,
				position	= { x = 144, y = 192 }
			},
			{
				animation	= 91,
				position	= { x = 160, y = 192 }
			},
			{
				animation	= 92,
				position	= { x = 208, y = 192 }
			},
			{
				animation	= 93,
				position	= { x = 224, y = 192 }
			},
			{
				animation	= 67,
				position	= { x = 240, y = 192 }
			},
			{
				animation	= 94,
				position	= { x = 0, y = 208 }
			},
			{
				animation	= 95,
				position	= { x = 16, y = 208 }
			},
			{
				animation	= 96,
				position	= { x = 32, y = 208 }
			},
			{
				animation	= 97,
				position	= { x = 96, y = 208 }
			},
			{
				animation	= 98,
				position	= { x = 112, y = 208 }
			},
			{
				animation	= 99,
				position	= { x = 128, y = 208 }
			},
			{
				animation	= 100,
				position	= { x = 144, y = 208 }
			},
			{
				animation	= 101,
				position	= { x = 208, y = 208 }
			},
			{
				animation	= 102,
				position	= { x = 224, y = 208 }
			},
			{
				animation	= 103,
				position	= { x = 240, y = 208 }
			},
		}
	)--end load tiles

	function self:logic()
		self:basicLogic()
		--put your layer logic here
	end

	return self
end

