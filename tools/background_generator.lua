function make_tile(animation, x, y)
	desc = ""
	desc = desc .. "			{\n"
	desc = desc .. "				animation	= " .. animation .. ",\n"
	desc = desc .. "				position	= { x = " .. x .. ", y = " .. y .. " }\n"
	desc = desc .. "			},\n"
	return desc
end

function make_Layer_class(
	pName,
	pSpritePackName,
	pAnimationPackName,
	pTiles
)
	desc = ""
	desc = desc .. pName .. " = class()\n"
	desc = desc .. "function " .. pName .. ":new(pBackground)\n"
	desc = desc .. "	local self = GGE_Layer:new(\n"
	desc = desc .. "		" .. pName .. ".__dir .. \"" .. pSpritePackName .. "\",\n"
	desc = desc .. "		" .. pName .. ".__dir .. \"" .. pAnimationPackName .. "\",\n"
	desc = desc .. "		pBackground\n"
	desc = desc .. "	)\n"
	desc = desc .. "	self:loadTiles(\n"
	desc = desc .. "		{\n"
	desc = desc .. pTiles
	desc = desc .. "		}\n"
	desc = desc .. "	)--end load tiles\n\n"
	
	desc = desc .. "	function self:logic()\n"
	desc = desc .. "		self:basicLogic()\n"
	desc = desc .. "		--put your layer logic here\n"
	desc = desc .. "	end\n\n"
	
	desc = desc .. "	return self\n"
	desc = desc .. "end\n"
	return desc
end

function make_BG_class(
	pName,
	pWidth,
	pHeight,
	pLayerNumber
)
	desc = ""
	desc = desc .. pName .. " = class()\n"
	desc = desc .. "function " .. pName .. ":new()\n"
	desc = desc .. "	local self	= GGE_Background:new()\n"
	desc = desc .. "	self.mWidth	= " .. pWidth .. "\n"
	desc = desc .. "	self.mHeight= " .. pHeight .. "\n"
	
	--gera os layers
	for iterator = 1, pLayerNumber, 1 do
		desc = desc .. "	self:addLayer(" .. pName .. "_layer_" .. iterator .. ":new(self))\n"
	end	
	
	desc = desc .. "\n	function self:logic()\n"
	desc = desc .. "		self:basicLogic()\n"
	desc = desc .. "		--put your background logic here\n"
	desc = desc .. "	end\n\n"
	desc = desc .. "	return self\n"
	desc = desc .. "end\n"
	return desc
end

